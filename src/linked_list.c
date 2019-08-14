#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

LinkedList* newLinkedList() {
	LinkedList *s = malloc(sizeof(LinkedList));
	if (!s) return NULL;
	s->incrementSize = 8;
	s->currentSize = s->incrementSize;
	s->linked_list = malloc((s->currentSize) * sizeof(int));
	if(!(s->linked_list)) {
		free(s);
		return NULL;
	}
	s->top = 0;
	return s;
}
int push(LinkedList *s, int d) {
	if (s->top == s->currentSize) {
		int *temp;
		(s->currentSize) += (s->incrementSize);
		temp = realloc(s->linked_list, (s->currentSize) * sizeof(int));
		if(!temp) {
			free(s->linked_list);
			free(s);
			return 0;
		}
		s->linked_list = temp;
	}
	(s->linked_list)[(s->top)++] = d;
	return 1;
}
int pop(LinkedList *s) {
	if (!(s->top)) return -1;
	int retVal = (s->linked_list)[--(s->top)];
	int decSize = (s->incrementSize) << 1;
	if (((s->currentSize) - (s->top)) > decSize) {
		int *temp;
		(s->currentSize) -= decSize;
		temp = realloc(s->linked_list, (s->currentSize) * sizeof(int));
		if(!temp) {
			(s->currentSize) += decSize;
		} else {
			s->linked_list = temp;
		}
	}
	return retVal;
}
int top(LinkedList *s) {
	if (!(s->top)) return -1;
	return (s->linked_list)[(s->top) - 1];
}
int size(LinkedList *s) {
	return s->top;
}
void display(LinkedList *s) {
	int i;
	for (i = 0; i < s->top; ++i) printf("%d, ", s->linked_list[i]);
	puts("End");
}
void freeLinkedList(LinkedList *s) {
	free(s->linked_list);
	free(s);
}
