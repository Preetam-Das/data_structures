/* Tue May  3 09:49:41 PM IST 2022 */
/* Author: preetamsad */

#include "darray.h"
#include <stdlib.h>
#include <stdio.h>

/* Returns a new dynamic array pointer with a capacity set by BASE_SIZE */

dArr* new_da()
{
    dArr *temp = (dArr*) malloc(sizeof(dArr));
    temp->arr = (int*) malloc(sizeof(int) * BASE_SIZE);

    if (temp == NULL || temp->arr == NULL) {
	fputs("malloc failed.\n", stderr);
	free(temp);
	free(temp->arr);
	exit(MALLOC_FAIL);
    }
	
    temp->size = 0;
    temp->capacity = BASE_SIZE;

    return temp;
}

/* Add element at the end of the dynamic array keeping */
/* in check the size and capacity and reallocating if */ 
/* nedded */

void add_da(dArr * d, int element)
{
    if (d == NULL) {
       fputs("Array is empty.\n", stderr);
       exit(EMPTY_ARR);
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
	fputs("Position out of bound.\n", stderr);
	exit(OUT_OF_BOUND);
    }
        
    for (int i = d->size; i > pos; i--) {
	d->arr[i] = d->arr[i - 1];
    }

    d->arr[pos] = element;
    d->size++;

    resize_da(d);
}

/* Resize the array according to your need */

void resize_da(dArr *d)
{
    if (d->size >= (d->capacity)/2) {
       d->arr = (int*) realloc((void*) d->arr, sizeof(int) * (d->capacity * 2));
       d->capacity *= 2;
    }
}
