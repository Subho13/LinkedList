#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
typedef struct linked_list {
	int incrementSize;
	unsigned int currentSize, top;
	int *linked_list;
} LinkedList;

LinkedList* newLinkedList();
int push(LinkedList*, int);
int pop(LinkedList*);
int top(LinkedList*);
int size(LinkedList*);
void display(LinkedList*);
void freeLinkedList(LinkedList*);
#endif
