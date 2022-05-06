/* Tue May  3 09:49:41 PM IST 2022 */
/* Author: preetamsad */
/* Title: Dynamic Array Implementation */

#include "darray.h"
#include <stdlib.h>
#include <stdio.h>

/* Returns a new dynamic array pointer with a capacity set by BASE_SIZE */

dArr* new_da()
{
    dArr *temp = (dArr*) malloc(sizeof(dArr));
    temp->arr = (int*) malloc(sizeof(int) * BASE_SIZE);

    if (temp == NULL || temp->arr == NULL) {
	hanlde_error(temp, MALLOC_FAIL);
    }
	
    temp->size = 0;
    temp->capacity = BASE_SIZE;

    return temp;
}

/* Resize the array according to your need */

void resize_da(dArr *d)
{
    if (d->size >= (d->capacity)/2) {
       d->arr = (int*) realloc((void*) d->arr, sizeof(int) * (d->capacity * 2));
       d->capacity *= 2;
    }
}

/* Add element at the end of the dynamic array keeping */
/* in check the size and capacity and reallocating if */ 
/* nedded */

void add_da(dArr * d, int element)
{
    if (d == NULL) {
       hanlde_error(d, EMPTY_ARR);
    }

    resize_da(d);

    d->arr[d->size] = element;
    d->size++;
}

/* Insert an element anywhere in the array and */
/* reallocating as neccessary */

void insert_da(dArr *d, int element, int pos) 
{
    if (pos < 0 || pos > d->size) {
	hanlde_error(d, OUT_OF_BOUND);
    }
        
    for (int i = d->size; i > pos; i--) {
	d->arr[i] = d->arr[i - 1];
    }

    d->arr[pos] = element;
    d->size++;

    resize_da(d);
}

/* Delete an element based on the index position */
/* and reallocate as neccessary */

void del_da(dArr *d, int pos)
{
    //bound check
    if (pos < 0 || pos >= d->size) {
	hanlde_error(d, OUT_OF_BOUND);
    }

    for (int i = pos + 1; i < d->size; i++) {
	d->arr[i - 1] = d->arr[i];
    }

    d->size--;
    resize_da(d);

}

/* Error Handling */

void hanlde_error(dArr *d, enum error_code e)
{
    switch(e) {
	case 0:
	    fputs("\nMalloc denied to return any memory :,).\n", stderr);
	    free(d);
	    break;
	case 1:
	    fputs("\nArray is Empty. Nothing to do here.\n", stderr);
	    free(d->arr);
	    break;
	case 2:
	    fputs("\nDon't try to cross the boundaries. Only garbage here :D.\n", stderr);
	    break;
	default:
	    break;
    }
}
