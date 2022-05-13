#include "darray.h"
#include "stdio.h"

int main()
{
    dArr *d = new_da();
    for (int i = 0; i < 5; i++) {
	add_da(d, i);
	printf("%d size: %d capacity: %d\n", d->arr[i], d->size, d->capacity);
    }
    del_da(d, 95);
}
