#include <stdio.h>
#include <string.h>
#include "service.h"


void add_product_srv(int id, char* type, char* manufacturer, char* model, float price, int quantity, List* list) {
	Product prod = create_product(id, type, manufacturer, model, price, quantity);
	for (int i = 0; i < list->length; i++)
		if (list->element[i].id == id) {
					printf("Existing ID!\n");
					delete_product(&prod);
					return;
				}
	if (validate_product(&prod) == 0) {
		printf("Invalid product!\n");
		delete_product(&prod);
	}
	else {
		add_product(prod, list);
	}
}

int update_price_srv(float price, List* list, int pos) {
	if (price > 0 && pos <= list->length) {
		list->element[pos].price = price;
		return 1;
	} else
		return 0;

}

int update_quantity_srv(int quantity, List* list, int pos) {
	if (quantity > 0 && pos <= list->length) {
		list->element[pos].quantity = quantity;
		return 1;
	}
	else
		return 0;
}

int delete_srv(List* list, int id) {
	for (int i = 0; i < list->length; i++)
		if (list->element[i].id == id) {
			delete(list, i);
			delete_product(&list->element[i]);
			return 1;
		}
	return 0;
}

Product get_srv(List* list, int pos) {
	return get(list, pos);
}

int get_size_srv(List* list) {
	return get_size(list);
}

/*
tralalala
*/
int compare_price(Product* prod1, Product* prod2) {
	return prod1->price > prod2->price;
}

int compare_quant(Product* prod1, Product* prod2) {
	return prod1->quantity > prod2->quantity;
}

//void sort_price(List* list) {
//	Product tmp;
//	for (int i = 0; i < list->length - 1; i++)
//		for (int j = i + 1; j < list->length; j++)
//			if (list->element[i].price > list->element[j].price) {
//				tmp = list->element[i];
//				list->element[i] = list->element[j];
//				list->element[j] = tmp;
//			}
//}

void sort_price(List* list) {
	Product tmp;
	for (int i = 0; i < list->length - 1; i++) {
		for (int j = i + 1; j < list->length; j++) {
			if (compare_price(&list->element[i], &list->element[j])) {
				tmp = list->element[i];
				list->element[i] = list->element[j];
				list->element[j] = tmp;
			}
		}
	}
}

void sort_quantity(List* list) {
	Product tmp;
	for (int i = 0; i < list->length - 1; i++)
		for (int j = i + 1; j < list->length; j++)
			if (compare_quant(&list->element[i], &list->element[j])) {
				tmp = list->element[i];
				list->element[i] = list->element[j];
				list->element[j] = tmp;
			}
}

List filter_manufacturer(List* list, char* manufacturer) {
	List lista_noua = create_empty();
	for (int i = 0; i < list->length; i++) {
		Product prod = get(list, i);
		if (strcmp(prod.manufacturer, manufacturer) == 0)
			add_product(create_product(prod.id, prod.type, prod.manufacturer, prod.model, prod.price, prod.quantity), &lista_noua);
	}
		return lista_noua;
}



List filter_price(List* list, float price) {
	List lista_noua = create_empty();
	for (int i = 0; i < list->length; i++) {
		Product prod = get(list, i);
		if (prod.price < price)
			add_product(create_product(prod.id, prod.type, prod.manufacturer, prod.model, prod.price, prod.quantity), &lista_noua);
	}
		return lista_noua;
}

List filter_quantity(List* list, int quantity) {
	List lista_noua = create_empty();
	for (int i = 0; i < list->length; i++) {
		Product prod = get(list, i);
		if (prod.quantity < quantity)
			add_product(create_product(prod.id, prod.type, prod.manufacturer, prod.model, prod.price, prod.quantity), &lista_noua);
	}
		return lista_noua;
}
