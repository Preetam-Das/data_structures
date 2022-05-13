/* Tue May  3 09:21:35 PM IST 2022 */
/* Author: preetamsad */
/* Title: Dynamic Array Defination */

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

/* Minimum size allocated when a new array is created *1/ */ 
#define BASE_SIZE 10

/* Functions to add element, insert a element and to delete an */
/* element */

dArr* new_da();
void add_da(dArr *d, int element);
void insert_da(dArr *d, int element, int pos);
void del_da(dArr *d, int pos);
void resize_da(dArr *d);

/* Error Handling */ 

enum error_code {MALLOC_FAIL, EMPTY_ARR, OUT_OF_BOUND};
void hanlde_error(dArr *d, enum error_code e);

#endif
