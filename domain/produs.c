#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "produs.h"



Product create_product(int id, char* type, char* manufacturer, char* model, float price, int quantity) {
	Product p;
	p.id = id;

	int nr_char = (int) strlen(type) + 1;
	p.type = malloc(nr_char * sizeof(char));
	strcpy(p.type, type);

	nr_char = (int)strlen(manufacturer) + 1;
	p.manufacturer = malloc(nr_char * sizeof(char));
	strcpy(p.manufacturer, manufacturer);

	nr_char = (int)strlen(model) + 1;
	p.model = malloc(nr_char * sizeof(char));
	strcpy(p.model, model);

	p.price = price;
	p.quantity = quantity;

	return p;
}

/*
* Valideaza o entitate de tip Produs
* param: prod (struct)
* return: 1 - daca entitatea e valida
*		  0 - daca entitatea nu e valida
*/
int validate_product(Product* prod) {
	if (prod->id < 0) {
		return 0;
	}
	if (strcmp(prod->type, "") == 0) {
		return 0;
	}
	if (strcmp(prod->manufacturer, "") == 0) {
		return 0;
	}
	if (strcmp(prod->model, "") == 0) {
		return 0;
	}
	if (prod->price < 0) {
		return 0;
	}
	if (prod->quantity < 0) {
		return 0;
	}
	return 1;
}


/*
  Sterge elementele entitatii de tipul Produs
  param: prod (struct)
*/
void delete_product(Product* prod) {
	free(prod->type);
	free(prod->manufacturer);
	free(prod->model);
	prod->id = -1;
	prod->type = NULL;
	prod->manufacturer = NULL;
	prod->model = NULL;
	prod->price = -1;
	prod->quantity = -1;
}


