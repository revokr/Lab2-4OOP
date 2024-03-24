#include "repository.h"




/*
	Adds and validates a product to the list
	param id: product id (int)
	param type: product type (char*)
	param manufacturer: product manufacturer (char*)
	param model: product model (char*)
	param price: product price (float)
	param quantity: product quantity (int)
	param list: list (List)
*/
void add_product_srv(int id, char* type, char* manufacturer, char* model, float price, int quantity, List* list);

/*
	Updates the price of the product on position pos with the new price validated
	param price: new price (float)
	param list: list
	param pos: position of the element
	return: returns 1 if the update was successful, 0 otherwise
*/
int update_price_srv(float price, List* list, int pos);

/*
	Updates the quantity of the product on position pos with the new quantity validated
	param quantity: new quantity (int)
	param list: list
	param pos: position of the element
	return: returns 1 if the update was successful, 0 otherwise
*/
int update_quantity_srv(int quantity, List* list, int pos);

/*
	Deletes the product with the id from the list
	param id: product id (int)
	param list: list
	return: returns 1 if the delete was successful, 0 otherwise
*/
int delete_srv(List* list, int id);

/*
	Returns the product from the list on position pos
	param list: list
	param pos: position of the element
	return: returns the product on position pos
*/
Product get_srv(List* list, int pos);

/*
	Returns the size of the list
	param list: list
	return: returns the size of the list
*/
int get_size_srv(List* list);


/*
	Sorts the list by price
	param list: list
	return: returns a list with the elemenets with the price sorted
*/
void sort_price(List* list);

/*
	Sorts the list by quantity
	param list: list
	return: returns a list with the elemenets with the quantity sorted
*/
void sort_quantity(List* list);

/*
	Filters the list by a manufacturer given
	param list: list
	param manufacturer: manufacturer
	return: returns a list with the elemenets with the manufacturer given
*/
List filter_manufacturer(List* list, char* manufacturer);

/*
	Filters the list by a price given
	param list: list
	param price: price
	return: returns a list with the elemenets with the price lower than the one given given
*/
List filter_price(List* list, float price);

/*
	Filters the list by a quantity given
	param list: list
	param quantity: quantity
	return: returns a list with the elemenets with the quantity lower than the one given given
*/
List filter_quantity(List* list, int quantity);

typedef int(*compare)(Product* prod1, Product* prod2);
