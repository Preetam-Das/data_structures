#include "darray.h"
#include "stdio.h"

int main()
{
    dArr *d = new_da();
    for (int i = 0; i < 45; i++) {
	add_da(d, i);
	printf("%d ", d->arr[i]);
	printf("size: %d capacity: %d\n", d->size, d->capacity);
    }
}
