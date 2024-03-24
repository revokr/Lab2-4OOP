#include "repository.h"
#include <stdio.h>
#include <stdlib.h>

List create_empty() {
	List list;
	list.cap = 2;
	list.element = (Product*)malloc(list.cap * sizeof(Product));
	list.length = 0;
	return list;
}

void destroy_list(List* list) {
	for (int i = 0; i < list->length; i++) {
		/*Product prod = get(&list, i);*/
		delete_product(&list->element[i]);
	}
	free(list->element);
	list->length = 0;
}

void add_product(Product prod, List* list) {
	if (list->length == list->cap) {
		int new_cap = list->cap * 2;
		Product* new_element = malloc(new_cap * sizeof(Product));
		for (int i = 0; i < list->length; i++)
			new_element[i] = list->element[i];
		free(list->element);
		list->element = new_element;
		list->cap = new_cap;
	}
	list->element[list->length] = prod;
	list->length++;
}



void delete(List* list, int pos) {
	/*if (list->length == 1)
		destroy_list(&list);*/
	for (int i = pos; i < list->length - 1; i++)
		list->element[i] = list->element[i + 1];
	list->length--;
}

Product get(List* list, int pos) {
	return list->element[pos];
}

int get_size(List* list) {
	return list->length;
}


