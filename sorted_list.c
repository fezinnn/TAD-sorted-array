#include <stdio.h>
#include <stdlib.h>
#include "sorted_list.h"

typedef struct{
    int *numbers;
    int capacity;
    int size;
} t_sorted_list;


t_sorted_list *create_list(int initial_capacity){
    t_sorted_list *list = (t_sorted_list *)malloc(sizeof(t_sorted_list));

    if(list == NULL){
        return NULL;
    }

    list->numbers = (int *)malloc(initial_capacity * sizeof(int));
    list->capacity = initial_capacity;
    list->size = 0;

    return list;
}

int is_full(t_sorted_list *list){
    return list->size == list->capacity;
}

int is_empty(t_sorted_list *list){
    return list->size == 0;
}

void resize_list(t_sorted_list *list){
    list->capacity += 20;
    list->numbers = (int *)realloc(list->numbers, list->capacity * sizeof(int));
}

void insert_element(t_sorted_list *list, int element){
    if(is_full(list)){
        resize_list(list);
    }

    int i = list->size - 1;
    while (i >= 0 && list->numbers[i] > element){
        list->numbers[i + 1] = list->numbers[i];
        i--;
    }

    list->numbers[i + 1] = element;
    list->size++;
}

void print_list(t_sorted_list *list)
{
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->numbers[i]);
    }
    printf("\n");
}

int find_element(t_sorted_list *list, int begin, int end, int element){
    int i = (begin + end) / 2;

    if(begin > end){
        return -1;
    }

    if(list->numbers[i] == element){
        return i;
    }

    if(list->numbers[i] < element){
        return find_element(list, i + 1, end, element);
    } else{
        return find_element(list, begin, i - 1, element);
    }
}

void remove_element(t_sorted_list *list, int element) {
    int index = find_element(list, 0, list->size, element);

    if (index != -1) {
        for (int i = index; i < list->size - 1; i++) {
            list->numbers[i] = list->numbers[i + 1];
        }

        list->size--;
    }
}

void destroy_list(t_sorted_list *list){
    free(list->numbers);
    free(list);
}

t_sorted_list *reverse_and_copy(t_sorted_list *list){
    t_sorted_list *reversed_list = create_list(list->capacity);

    if(reversed_list == NULL){
        return NULL;
    }

    for(int i = list->size - 1, j = 0; i >= 0; i--, j++){
        reversed_list->numbers[j] = list->numbers[i];
    }
    
    reversed_list->size = list->size;

    return reversed_list;
}




int main(){
    t_sorted_list *myList = create_list(10);

    // Test insertions
    insert_element(myList, 8);
    insert_element(myList, 2);
    insert_element(myList, 6);
    insert_element(myList, 3);
    insert_element(myList, 10);
    insert_element(myList, 5);
    insert_element(myList, 4);
    insert_element(myList, 9);
    insert_element(myList, 1);
    insert_element(myList, 7);
    
    printf("\nLISTA NORMAL 1 A 10:\n");
    print_list(myList); // Expected: 1 2 3 4 5 6 7 8 9 10

    // Test removal
    printf("\n\n\nLISTA REMOVENDO O 5:\n");
    remove_element(myList, 5);
    print_list(myList); // Expected: 1 2 3 4 6 7 8 9 10

    printf("\n\n\nLISTA INVERTIDA:\n");
    t_sorted_list *reversed_list = reverse_and_copy(myList);
    print_list(reversed_list);

    destroy_list(myList);
    destroy_list(reversed_list);
    return 0;
}
