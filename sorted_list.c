#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *numbers;
    int capacity;
    int size;
} t_sorted_list;

// Implementadas
t_sorted_list *create_list(int initial_capacity);
void insert_element(t_sorted_list *list, int element);
void remove_element(t_sorted_list *list, int element);
void resize_list(t_sorted_list *list);
void print_list(t_sorted_list *list);

// Não implementadas
int find_element(t_sorted_list *list, int element);
void free_list(t_sorted_list *list);

t_sorted_list *create_list(int initial_capacity)
{
    t_sorted_list *list = (t_sorted_list *)malloc(sizeof(t_sorted_list));
    list->numbers = (int *)malloc(initial_capacity * sizeof(int));
    list->capacity = initial_capacity;
    list->size = 0;
    return list;
}

void insert_element(t_sorted_list *list, int element)
{
    if (list->size == list->capacity)
    {
        resize_list(list);
    }
    int i = list->size - 1;
    while (i >= 0 && list->numbers[i] > element)
    {
        list->numbers[i + 1] = list->numbers[i];
        i--;
    }
    list->numbers[i + 1] = element;
    list->size++;
}

void resize_list(t_sorted_list *list)
{
    // list->capacity *= 2;
    list->capacity += 20;
    list->numbers = (int *)realloc(list->numbers, list->capacity * sizeof(int));
}

void remove_element(t_sorted_list *list, int element)
{
    int index = find_element(list, element);
    if (index != -1)
    {
        for (int i = index; i < list->size - 1; i++)
        {
            list->numbers[i] = list->numbers[i + 1];
        }
        list->size--;
    }
}

void print_list(t_sorted_list *list)
{
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->numbers[i]);
    }
    printf("\n");
}

int find_element(t_sorted_list *list, int element)
{
}

void free_list(t_sorted_list *list)
{
}

int main()
{
    t_sorted_list *myList = create_list(10);

    // Test insertions
    insert_element(myList, 5);
    insert_element(myList, 3);
    insert_element(myList, 9);
    print_list(myList); // Expected: 3 5 9

    // Test removal
    remove_element(myList, 5);
    print_list(myList); // Expected: 3 9

    free_list(myList);
    return 0;
}