#include <stdio.h>
#include <stdlib.h>
#include "sorted_list.h"

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
