#include <stdio.h>
#include "linked_list.h"

int main()
{
    linked_list *l = new_llist();
    for (int i = 0 ; i < 5 ; i++) {
	insert_llist(l, l->size, 69 + i);
    }
    print_llist(l);
    del_llist(l, -1);
    print_llist(l);
}
