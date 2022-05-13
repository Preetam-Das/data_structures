/* Wed May  4 07:05:09 PM IST 2022 */
/* Author: preetam-sad */
/* Title: Linked List Definations */
#include <stdbool.h>


#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/* Structure to represent a node */ 
/* of the Linked list */

struct node {
    int data;
    struct node *next;
};

struct linked_list {
    struct node *head;
    int size;
};

typedef struct linked_list linked_list;

/* Basic functionalities of a linked_list */

linked_list* new_llist();
void print_llist(linked_list *l);
bool isempty(linked_list *l);
void insertbg_llist(linked_list *l, int element);
void insertend_llist(linked_list *l, int element);
void insert_llist(linked_list *l, int pos, int element);
void del_llist(linked_list *l, int pos);
void delbg_llist(linked_list *l);
void delend_llist(linked_list *l);
void peek_llist(linked_list *l, int pos);
void get_index_llist(linked_list *l, int element);

/* Error Handling */

enum error_code {MALLOC_FAIL, EMPTY_LIST, OUT_OF_BOUNDARY};
void handle_error(linked_list *l, enum error_code e);

#endif
