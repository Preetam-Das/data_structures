#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST
#define max_list_size 10

enum type {INT, CHAR, STRING, FLOAT};

struct node {
	void *data;
	struct node *prev, *next;
};

struct ll {
	struct node *head, *tail;
	int size;
	enum type type;
};

struct ll* newlist(enum type t)
{
	struct ll *temp;
	temp = (struct ll *) malloc(sizeof(struct ll));
	temp->head = NULL;
	temp->tail = NULL;
	temp->size = 0;
	temp->type = t;

	return temp;
}

bool islistempty(struct ll *list)
{
	/* fputs(list->size? "true\n" : "false\n", stdout); */
	return list->size == 0;
}

void *addelement(struct ll *l, va_list v)
{ 
	if (l->type == 0) { 
		int *int_poitner; 
		int_poitner = (int *) malloc(sizeof(int)); 
		*int_poitner = (va_arg(v, int)); 
		return (void *) int_poitner; 
	} 
	if (l->type == 1) { 
		char *char_pointer; 
		char_pointer = (char *) malloc(sizeof(char)); 
		*char_pointer = (char) (va_arg(v, int)); 
		return (void *) char_pointer; 
	} 
	if (l->type == 2) { 
		char *string_pointer; 
		string_pointer = (char *) malloc(sizeof(char)); 
		strcpy(string_pointer, va_arg(v, char *)); 
		return (void *) string_pointer; 
	} 
	if (l->type == 3) { 
		float *float_pointer; 
		float_pointer = (float *) malloc(sizeof(float)); 
		*float_pointer = (float) va_arg(v, double); 
		return (void *) float_pointer; 
	} 
} 

void insert_bg(struct ll *l, va_list v)
{
	struct node *temp;
	temp = (struct node*) malloc(sizeof(struct node));
	temp->data = addelement(l, v);

	temp->prev = NULL;
	temp->next = l->head;
	if (l->head != NULL) l->head->prev = temp;
	l->head = temp;	
	l->size++;

	va_end(v);
}

void insert_end(struct ll *l, va_list v)
{
	if (l->head == NULL) return insert_bg(l, v);

	struct node *temp;
	temp = (struct node *) malloc(sizeof(struct node));
	temp->data = addelement(l, v); 

	temp->prev = NULL;
	temp->next = NULL;

	struct node* ptr = l->head;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	temp->prev = ptr;
	ptr->next = temp;
	l->size++;
}


void insert(struct ll *l, int pos, int count, ...) 
{
	va_list v;
	va_start(v, count);
	
	for (int i = 0; i < count; i++) {
		if (pos == 0) insert_bg(l, v);
		else if (pos == l->size) insert_end(l, v);
		else {	
			struct node *temp;
			temp = (struct node*) malloc(sizeof(struct node));
			temp->data = addelement(l, v);
			
			struct node *ptr = l->head;
			for (int i = 0; i < pos - 1; i++) {
				ptr = ptr->next;
			}
			temp->prev = ptr;
			temp->next = ptr->next;
			ptr->next = temp;
			temp->next->prev = temp;
			l->size++;

			va_end(v);
		}
		pos++;
	}
}


void printelement(struct ll *l, struct node *ptr)
{
	if (l->type == 0) printf("%d ", *((int *) ptr->data));
	else if (l->type == 1) printf("%c ", *((char *) ptr->data));
	else if (l->type == 2) printf("%s ", ptr->data);
	else if (l->type == 3) printf("%f ", *((float *) ptr->data));
}

void display(struct ll *l)
{
	struct node *ptr = l->head;
	while(ptr != NULL) {
		printelement(l, ptr);
		ptr = ptr->next;
	}
	fputs("\n", stdout);
}

int del_bg(struct ll *l)
{
	if (islistempty(l)) {
		fputs("List is empty.\n", stdout);
		return 12345;
	}

	int removed = *((int *)l->head->data);

	if (l->size == 1) {
		free(l->head);
		l->head = NULL;
		l->size--;
		return removed;
	}

	l->head = l->head->next;
	free(l->head->prev);
	l->head->prev = NULL;
	l->size--;
	return removed;
}

int del_end(struct ll *l)
{

	if (islistempty(l)) {
		fputs("List is empty.\n", stdout);
		return 12345;
	}

	int removed; 
	
	if (l->size == 1) return del_bg(l);

	struct node *ptr = l->head;
	while(ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->prev->next = NULL;
	removed = *((int*) ptr->data);
	free(ptr);
	l->size--;
	return removed;
}

int del_any(struct ll *l, int pos)
{

	if (islistempty(l)) {
		fputs("List is empty.\n", stdout);
		return 12345;
	}

	if (pos == 0) return del_bg(l);
	if (pos == l->size - 1) return del_end(l);
	
	int removed;

	struct node *ptr = l->head;
	for (int i = 0; i < pos - 1; i++) {
		ptr = ptr->next;
	}
	struct node *temp = ptr->next;
	ptr->next = temp->next;
	ptr->next->prev = temp->prev;
	removed = *((int*) temp->data);
	free(temp);
	l->size--;
	return removed;
	/* printf("%d\n", *((int*)temp->data)); */
	/* printf("%d\n", *((int*)ptr->prev->data)); */
}


#endif
