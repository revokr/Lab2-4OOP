//8. Magazin electronice
//
//Creati o aplicatie care permite gestiunea stocului de produse intr - un magazin de electronice.
//Fiecare produs are un identificator unic, tip(laptop, frigider, televizor, etc), producator, model,
//pret, cantitate.
//Aplicatia permite :
//a) Adaugarea de noi produse.Daca produsul este deja in stoc trebuie actualizat cantitatea
//b) Actualizare produse(modificare pret sau cantitate)
//c) Stergere produsd
//d) Vizualizare produse din stoc, ordonat dupa pret, cantitate(crescator / descrescator)
//e) Vizualizare lista de produse filtrate dupa un criteriu(producator, pret, cantitate)

typedef struct {
	int id;
	char* type;
	char* manufacturer;
	char* model;
	float price;
	int quantity;
} Product;


/*
	Creates an entity of type Product
	param id: (int)
	param type: (char*)
	param manufacturer: (char*)
	param model: (char*)
	param price: (float)
	param quantity: (int)
	return: (struct) Product
*/
Product create_product(int id, char* type, char* manufacturer, char* model, float price, int quantity);


/*
	Validates an entity of type Product
	param prod: (struct)
	return: (int) 1 if the entity is valid, 0 otherwise
*/
int validate_product(Product* prod);


/*
  Deletes an entity of type Product
  param prod: (struct)
*/
void delete_product(Product* prod);
