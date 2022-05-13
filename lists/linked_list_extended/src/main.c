#include <stdio.h>
#include "headers.h"
#include "linked_list.h"


int main() {
	struct ll *l = newlist(INT);
	struct ll *sl = newlist(STRING);

	insert(l, 0, 3, 1, 2, 3);
	display(l);
	insert(l, 0, 3, "preeatm", "koustav", "soujanna");
	display(l);
}
