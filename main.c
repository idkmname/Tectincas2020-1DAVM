#include "virtualidad.h"

typedef struct persona{
	char nombre[20];
	int dia;
	int mes;
	int anio;
}persona;



void mostrarMenu() {
	int opcion = 0;
	persona matriz[12][5];
	do {
		printf(" Opciones para matrices \n\n");
		printf("1. Ingresar un nuevo usuario\n");
		printf("2. Mostrar cumpleanios por mes\n");
		printf("3. extra2\n");
		printf("4. extra1\n");
		printf("0. Salir\n\n");
		printf(" Opc: ");
		scanf("%d", &opcion);
		switch (opcion) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4: break;
			
		}
		//Cuando el usuario ingrese 0 se terminará el menu
	} while(opcion!=0);
}

int main(){
	//Menu que muestra las opciones disponibles
	mostrarMenu ();
	return 0;
}