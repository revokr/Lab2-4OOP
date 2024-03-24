#include <string.h>
#include "teste.h"
#include "ui.h"


void run_all_tests() {
	teste_create_product();
	teste_delete_product();
	teste_validator();
	teste_repo();
	teste_service();
	//printf("teste rulate cu succes!");
}

void Add_product(List* list) {
	int id, quantity;
	char type[20], manuf[20], model[20];
	float price;
	printf("choose id:");
	scanf("%d", &id);
	printf("\n");
	

	printf("choose type:");
	scanf("%s", &type);
	printf("\n");

	printf("choose manufacturer:");
	scanf("%s", &manuf);
	printf("\n");

	printf("choose model:");
	scanf("%s", &model);
	printf("\n");

	printf("choose price:");
	scanf("%f", &price);
	printf("\n");

	printf("choose quantity:");
	scanf("%d", &quantity);
	printf("\n");
	add_product_srv(id, type, manuf, model, price, quantity, list);
}

void Delete_product(List* list) {
	int id;
	printf("choose id:");
	scanf("%d", &id);
	printf("\n");


	delete_srv(list, id);
}

void Update_price(List* list) {
	float price;
	int id;
	printf("choose id :");
	scanf("%d", &id);
	printf("\n");
	for (int i = 0; i < list->length; i++)
		if (list->element[i].id == id) {
			printf("choose price :");
			scanf("%f", &price);
			printf("\n");
			update_price_srv(price, list, i);
			return;
		}
}

void Update_quantity(List* list) {
	int id, quant;
	printf("choose id :");
	scanf("%d", &id);
	printf("\n");
	for (int i = 0; i < list->length; i++)
		if (list->element[i].id == id) {
			printf("choose quantity :");
			scanf("%d", &quant);
			printf("\n");
			update_quantity_srv(quant, list, i);
			return;
		}
}

void Print(List* list) {
	for (int i = 0; i < list->length; i++) {
		printf("%d  %s", list->element[i].id, list->element[i].type);
		printf("  %s", list->element[i].manufacturer);
		printf("  %s  %f", list->element[i].model, list->element[i].price);
		printf("  %d", list->element[i].quantity);
		printf("\n");
	}
}

void Print_sorted_price(List* list) {
	sort_price(list);
	Print(list);
}

void Print_sorted_quantity(List* list) {
	sort_quantity(list);
	Print(list);
}

void Print_filtered_manufacturer(List* list) {
	char manuf[20];
	printf("choose manufacturer:");
	scanf("%s", &manuf);
	printf("\n");
	List listutza = filter_manufacturer(list, manuf);
	Print(&listutza);
}

void Print_filtered_price(List* list) {
	float price;
	printf("choose price:");
	scanf("%f", &price);
	printf("\n");
	List listutza = filter_price(list, price);
	Print(&listutza);
}

void Print_filtered_quantity(List* list) {
	int quant;
	printf("choose quantity:");
	scanf("%d", &quant);
	printf("\n");
	List listutza = filter_quantity(list, quant);
	Print(&listutza);
}

void Print_menu() {
	printf("x : close console\n");
	printf("add : add an element\n");
	printf("delete : delete an element\n");
	printf("print : print current elements\n");
	printf("sort_price : sorts elemenets by price\n");
	printf("sort_quantity : sorts elements by quantity\n");
	printf("upd_price : updates the price with a new one\n");
	printf("upd_quantity : updates the quantity with a new one\n");
	printf("flt_manuf : show the elements with a manufacturer given\n");
	printf("flt_price : show the elements with the price lower than one given\n");
	printf("flt_quantity : show the elements with the quantity lower than one given\n");
	printf("\n");
}

void run(List lista) {
	/*char* type;
	char* manuf;
	char* model;
	int id, quantity;
	float price;*/
	while (1) {
		char comm[20] = { '\0' };
		printf(">>>");
		scanf("%s", comm);

		if (strcmp(comm, "x") == 0)
			exit(0);
		if (strcmp(comm, "print") == 0)
			Print(&lista);

		if (strcmp(comm, "add") == 0) 
			Add_product(&lista);

		if (strcmp(comm, "sort_price") == 0)
			Print_sorted_price(&lista);

		if (strcmp(comm, "sort_quantity") == 0)
			Print_sorted_quantity(&lista);

		if (strcmp(comm, "delete") == 0)
			Delete_product(&lista);

		if (strcmp(comm, "flt_manuf") == 0)
			Print_filtered_manufacturer(&lista);

		if (strcmp(comm, "flt_price") == 0)
			Print_filtered_price(&lista);
		if (strcmp(comm, "flt_quantity") == 0)
			Print_filtered_quantity(&lista);
		if (strcmp(comm, "upd_price") == 0)
			Update_price(&lista);
		if (strcmp(comm, "upd_quantity") == 0)
			Update_quantity(&lista);
		
	}
	

}

