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
	fputs("malloc failed", stderr);
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

    if (d->size >= (d->capacity)/2) {
       d->arr = (int*) realloc((void*) d->arr, sizeof(int) * (d->capacity * 2));
       d->capacity *= 2;
    }

    d->arr[d->size] = element;
    d->size++;
}
