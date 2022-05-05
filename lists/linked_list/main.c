#include <stdio.h>
#include "linked_list.h"

int main()
{
    linked_list *l = new_llist();
    insert_llist(l, l->size, 69);
    insert_llist(l, l->size, 69520);
    insert_llist(l, l->size, 420);
    /* printf("%d\n", l->head->data); */
    print_llist(l);
    insert_llist(l, 1, 0);
    print_llist(l);
}
