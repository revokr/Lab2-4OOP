#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


#include <string.h>
#include "ui.h"

int main() {
	run_all_tests();
	system("cls");
	List lista = create_empty();
	Print_menu();
	//run(lista);
	destroy_list(&lista);
	_CrtDumpMemoryLeaks();
}
