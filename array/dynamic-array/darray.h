/* Tue May  3 09:21:35 PM IST 2022 */
/* Author: preetamsad */

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

/* Dynamic Array structure with size being the */ 
/* array's current size and capacity is the maximum */
/* no. of elements the array can accomodate without */
/* reallocating the entire array. */

struct dynamicArray {
    int *arr;
    int size;
    int capacity;
};
typedef struct dynamicArray dArr;

/* Minimum size allocated when a new array is created 
   and other macros */
#define BASE_SIZE 10
#define MALLOC_FAIL 12
#define EMPTY_ARR 13
#define OUT_OF_BOUND 14

/* Functions to add element, insert a element and to delete an */
/* element */

dArr* new_da();
void add_da(dArr *d, int element);
void insert_da(dArr *d, int element, int pos);
void del_da(dArr *d, int pos);
void resize_da(dArr *d);

#endif
