#include "service.h"


/*
	Runs all tests
*/
void run_all_tests();

/*
	Adds a product to the list
*/
void Add_product(List* list);


/*
	Deletes a product from the list
*/
void Delete_product(List* list);

/*
	Updates the price of an element
*/
void Update_price(List* list);

/*
	Updates the quantity of an element
*/
void Update_quantity(List* list);

/*
	Prints all elements in the list
*/
void Print(List* list);

/*
	Prints the elements sorted by price
*/
void Print_sorted_price(List* list);

/*
	Prints the elements sorted by quantity
*/
void Print_sorted_quantity(List* list);

/*
	Prints the element filtered by a manufacturer
*/
void Print_filtered_manufacturer(List* list);

/*
	Prints the elements lower than a price given
*/
void Print_filtered_price(List* list);

/*
	Prints menu of commands
*/
void Print_menu();

/*
	Runs the application
*/
void run(List lista);
