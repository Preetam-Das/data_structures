#include "darray.h"
#include "stdio.h"

int main()
{
    dArr *d = new_da();
    for (int i = 0; i < 5; i++) {
	add_da(d, i);
	printf("%d size: %d capacity: %d\n", d->arr[i], d->size, d->capacity);
    }
    insert_da(d, -99, d->size);
    fputs("\n", stdout);
    for (int i = 0; i < d->size; i++) {
	printf("%d size: %d capacity: %d\n", d->arr[i], d->size, d->capacity);
    }
    
    del_da(d, 0);
    fputs("\n", stdout);
    for (int i = 0; i < d->size; i++) {
	printf("%d size: %d capacity: %d\n", d->arr[i], d->size, d->capacity);
    }
}
