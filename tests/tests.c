#include <string.h>
#include <assert.h>

#include "teste.h"
#include "service.h"


void teste_create_product() {
	char type[20] = { "asd" };
	char manuf[20] = { "dsa" };
	char model[20] = { "d" };
	float price = 8.99;
	Product benchlets = create_product(1, type, manuf, model, price, 1);
	assert(benchlets.id == 1);
	assert(strcmp(benchlets.type, "asd") == 0);
	assert(strcmp(benchlets.manufacturer, "dsa") == 0);
	assert(strcmp(benchlets.model, "d") == 0);
	//assert(beculetz.price == 8.99);
	assert(benchlets.quantity == 1);
	delete_product(&benchlets);

}

void teste_delete_product() {
	Product beculetz = create_product(1, "bec", "firma_becuri", "neon", 8.99, 1);
	delete_product(&beculetz);
	assert(beculetz.id == -1);
	assert(beculetz.type == NULL);
	assert(beculetz.manufacturer == NULL);
	assert(beculetz.model == NULL);
	assert(beculetz.price == -1);
	assert(beculetz.quantity == -1);
}

void teste_validator() {
	Product prod1 = create_product(1, "suc", "coca_cola", "lime", 8.99, 1);
	assert(validate_product(&prod1) == 1);
	delete_product(&prod1);
	Product prod2 = create_product(-23, "suc", "coca_cola", "fanta", 8.99, 1);
	assert(validate_product(&prod2) == 0);
	delete_product(&prod2);
	Product prod3 = create_product(23, "", "coca_cola", "fanta", 8.99, 1);
	assert(validate_product(&prod3) == 0);
	delete_product(&prod3);
	Product prod4 = create_product(23, "adssa", "", "fanta", 8.99, 1);
	assert(validate_product(&prod4) == 0);
	delete_product(&prod4);
	Product prod5 = create_product(23, "asdasd", "coca_cola", "", 8.99, 1);
	assert(validate_product(&prod5) == 0);
	delete_product(&prod5);
	Product prod6 = create_product(23, "asda", "coca_cola", "fanta", -8, 1);
	assert(validate_product(&prod6) == 0);
	delete_product(&prod6);
	Product prod7 = create_product(23, "sdad", "coca_cola", "fanta", 8.99, -11);
	assert(validate_product(&prod7) == 0);
	delete_product(&prod7);
}

//teste REPO
void teste_repo() {
	List lista = create_empty();
	assert(lista.length == 0);
	Product banane = create_product(1, "banane", "trunki punki", "coapte", 12.39, 1);
	add_product(banane, &lista);
	delete_product(&banane);
	assert(get_size(&lista) == 1);

	Product mere = create_product(2, "mere", "munki lunki", "gara", 23, 54);
	add_product(mere, &lista);
	delete_product(&mere);
	delete(&lista, 0);
	assert(get_size(&lista) == 1);
	delete(&lista, 0);
	assert(get_size(&lista) == 0);

	Product MrProppper = create_product(23, "detergent", "sanital", "clor+", 19.99, 1);
	add_product(MrProppper, &lista);
	//delete_product(&MrProppper);
	assert(get(&lista, 0).id == MrProppper.id);
	assert(get_size(&lista) == 1);

	destroy_list(&lista);
	//assert(get_size(&lista) == 0);

}


void teste_service() {
	List lista = create_empty();
	char type[20] = { "asd" };
	char manuf[20] = { "dsa" };
	char model[20] = { "d" };
	add_product_srv(1, type, manuf, model, 9, 1, &lista);

	char type1[20] = { "asdsd" };
	char manuf1[20] = { "dsfa" };
	char model1[20] = { "dff" };
	add_product_srv(2, type1, manuf1, model1, 34, 1, &lista);

	Product prod_test = create_product(2, type1, manuf1, model1, 34, 1);
	assert(get_srv(&lista, 1).id == prod_test.id);

	assert(get_size_srv(&lista) == 2);
	delete_product(&prod_test);

	delete_srv(&lista, 2);

	assert(get_size_srv(&lista) == 1);
	assert(update_price_srv(100, &lista, 0) == 1);
	assert(update_price_srv(-100, &lista, 0) == 0);

	char type2[20] = { "assadd" };
	char manuf2[20] = { "dssada" };
	char model2[20] = { "sadd" };
	add_product_srv(3, type2, manuf2, model2, 34, 12, &lista);

	assert(get_size(&lista) == 2);
	assert(update_quantity_srv(100, &lista, 0) == 1);
	assert(update_quantity_srv(-100, &lista, 0) == 0);

	char type3[20] = { "as12sadd" };
	char manuf3[20] = { "dssqwada" };
	char model3[20] = { "sawwdd" };
	add_product_srv(3, type3, manuf3, model3, 12, 112, &lista);

	assert(get_size(&lista) == 2);

	char type4[20] = { "" };
	char manuf4[20] = { "dssqwada" };
	char model4[20] = { "sawwdd" };
	add_product_srv(-5, type4, manuf4, model4, 12, 112, &lista);

	assert(get_size(&lista) == 2);
	//destroy_list(&lista);

	char type23[20] = { "portocale" };
	char manuf23[20] = { "rusia" };
	char model23[20] = { "mari" };
	add_product_srv(5, type23, manuf23, model23, 12, 400, &lista);
	//add_product_srv(1, type, manuf, model, 100, 1, &lista);
	//add_product_srv(2, type1, manuf1, model1, 34, 1, &lista);
	assert(get_size_srv(&lista) == 3);

	sort_price(&lista);
	assert(get_srv(&lista, 0).id == 5);

	sort_quantity(&lista);
	assert(get_srv(&lista, 2).id == 5);

	List listutza = filter_manufacturer(&lista, manuf23);
	assert(get_size_srv(&listutza) == 1);

	List listutza2 = filter_price(&lista, 13);
	assert(get_size_srv(&listutza2) == 1);

	List listutza3 = filter_quantity(&lista, 100);
	assert(get_size_srv(&listutza3) == 1);

	assert(delete_srv(&lista, 215) == 0);
	
	destroy_list(&lista);
	//assert(get_size_srv(&lista) == 0);

	destroy_list(&listutza);

	destroy_list(&listutza2);

	destroy_list(&listutza3);



}
