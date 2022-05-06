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
    if (l == NULL || l->size == 0 || l->head == NULL) {
	handle_error(l, EMPTY_LIST);
	return;
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

/* Delete from the beginning of the list */

void delbg_llist(linked_list *l)
{
    if (isempty(l)) {
	handle_error(l, EMPTY_LIST);
	fputs("hello\n", stdout);
	return;
    }

    struct node *temp = l->head;
    l->head  = l->head->next;

    free(temp);
    l->size--;
}

/* Delete from the end of the list */

void delend_llist(linked_list *l)
{
    if (isempty(l)) {
	handle_error(l, EMPTY_LIST);
	return;
    }
    
    if (l->size == 1) return delbg_llist(l);

    struct node *ptr = l->head;
    struct node *temp = l->head;

    while (ptr->next != NULL) {
	temp = ptr;
	ptr = ptr->next;
    }
    free(ptr);
    temp->next = NULL;
    l->size--;

}

/* Delete at a certain position of the list */

void del_llist(linked_list *l, int pos)
{
    if (pos < 0 || pos >= l->size) {
	handle_error(l, OUT_OF_BOUNDARY);
	return;
    }

    if (pos == 0) return delbg_llist(l);
    if (pos == l->size) return delend_llist(l); 

    struct node *ptr = l->head;
    struct node *temp = ptr;
    for (int i = 0; i < pos; i++) {
	temp = ptr;
	ptr = ptr->next;
    }

    temp->next = ptr->next;
    free(ptr);
    l->size--;
    
}
    
    
/* Error Handling */

void handle_error(linked_list *l, enum error_code e)
{
    switch(e) {
	case 0:
	    fputs("Malloc denied to return any memory :,).\n", stderr);
	    free(l);
	    break;
	case 1:
	    fputs("List is Empty. Nothing to do here.\n", stderr);
	    free(l->head);
	    break;
	case 2:
	    fputs("Don't try to cross the boundaries. Only garbage here :D.\n", stderr);
	    break;
	default:
	    break;
    }
}
