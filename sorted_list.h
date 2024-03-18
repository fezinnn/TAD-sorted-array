#ifndef SORTED_LIST_H
#define SORTED_LIST_H

typedef struct{
    int *numbers;
    int capacity;
    int size;
} t_sorted_list;

t_sorted_list *create_list(int initial_capacity);
int is_full(t_sorted_list *list);
int is_empty(t_sorted_list *list);
void resize_list(t_sorted_list *list);
void insert_element(t_sorted_list *list, int element);
void print_list(t_sorted_list *list);
int find_element(t_sorted_list *list, int begin, int end, int element);
void remove_element(t_sorted_list *list, int element);
void destroy_list(t_sorted_list *list);
t_sorted_list *reverse_and_copy(t_sorted_list *list);

#endif
