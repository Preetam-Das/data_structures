/* Wed May  4 07:15:18 PM IST 2022 */
/* Author: preetamsad */
/* Title: Linked List Implementation */

#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

/* Returns a new linked_list pointer */

linked_list* new_llist()
{
    linked_list *temp = (linked_list*) malloc(sizeof(linked_list));
    
    if (temp == NULL) {
	handle_error(temp, MALLOC_FAIL);
    }

    temp->head = NULL;
    temp->size = 0;
    return temp;
}

/* Prints the linked_list */

void print_llist(linked_list *l)
{
    if (l == NULL || l->head == NULL) {
	handle_error(l, EMPTY_LIST);
    }
    
    struct node *ptr = l->head;
    while(ptr != NULL) {
	printf("%d ", ptr->data);
	ptr = ptr->next;
    }
    fputs("\n", stdout);
}

/* Returns if the list is empty or not */

bool isempty(linked_list *l)
{
    return l->head == NULL;
}

/* Inserts an element in the beginning */

void insertbg_llist(linked_list *l, int element)
{
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = element;
    temp->next = l->head;
    l->head = temp;
    l->size++;
    return;
}

/* Inserts an element in the end */

void insertend_llist(linked_list *l, int element)
{
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = element;
    temp->next = NULL;

    if (isempty(l)) {
	return insertbg_llist(l, element);
    }

    struct node *ptr = l->head;
    while (ptr->next != NULL) {
	ptr = ptr->next;
    }
    ptr->next = temp;
    l->size++;
    return;
}

/* Inserts an element in a given position pos */

void insert_llist(linked_list *l, int pos, int element)
{
    if (pos < 0 || pos > l->size) {
	handle_error(l, OUT_OF_BOUNDARY);
	return;
    }

    if (pos == 0) return insertbg_llist(l, element);
    if (pos == l->size) return insertend_llist(l, element);
    
    struct node *ptr = l->head;
    for (int i = 0; i < pos - 1; i++) {
	ptr = ptr->next;
    }

    struct node *temp = (struct node*) (malloc(sizeof(struct node)));
    temp->data = element;
    temp->next = ptr->next;
    ptr->next = temp;
    l->size++;
    return;;
}

/* Error Handling */

void handle_error(linked_list *l, enum error_code e)
{
    switch(e) {
	case 0:
	    fputs("\nMalloc denied to return any memory :,).\n", stderr);
	    free(l);
	    break;
	case 1:
	    fputs("\nList is Empty. Nothing to do here.\n", stderr);
	    free(l->head);
	    break;
	case 2:
	    fputs("\nDon't try to cross the boundaries. Only garbage here :D.\n", stderr);
	    free(l->head);
	    break;
	default:
	    break;
    }
}
