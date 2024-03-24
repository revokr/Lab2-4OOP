#include "produs.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct {
	Product* element;
	int length;
	int cap;
} List;




/*
	Creates an empty list
	return: list
*/
List create_empty();

/*
	Destroys a list
*/
void destroy_list(List* list);

/*
	Adds a product to the list
	param prod: product to be added (Product)
	param list: list to which the product will be added (List)
*/
void add_product(Product prod, List* list);


/*
	Deletes a product from the list
	param list: list from which the product will be deleted (List)
	param pos: position of the product to be deleted (int)
*/
void delete(List* list, int pos);


/*
	Returns the product from the list at a given position
	param list: list from which the product will be returned (List)
	param pos: position of the product to be returned (int)
	return: product at the given position (Product)
*/
Product get(List* list, int pos);


/*
	Returns the size of the list
	param list: list from which the size will be returned (List)
	return: size of the list (int)
*/
int get_size(List* list);



