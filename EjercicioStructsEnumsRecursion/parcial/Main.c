#include "FuncionesCC.c"
#include <stdio.h>

void menu(){
	int fil, col, opcion, filTemp, i;
	local_t ** centroComercial;
	char nombre[35];
	
	printf("Ingrese la cantidad de pisos en su centro comercial: ");
	scanf("%d", &fil);
	printf("Ingrese la cantidad de locales en cada piso de su centro comercial: ");
	scanf("%d", &col);
	fil -= 1;
	col -= 1;
	definirTamanio(&centroComercial, fil, col);
	
	do {
		printf("\nOpciones para centro comercial: \n\n");
		printf("1. Agregar local comercial\n");
		printf("2. Mostrar locales por piso\n");
		printf("3. Buscar local comercial\n");
		printf("4. Modificar informacion de los locales\n");
		printf("5. Eliminar local comercial\n");
		printf("0. Salir del programa \n");
		printf("Opc: ");
		scanf("%d", &opcion);
		if ( opcion >= 0 && opcion <= 5 ){
			switch (opcion) {
				case 1:
					agregarNegocio(&centroComercial, fil, col);
					break;	
				case 2:
					printf("Que piso desea revisar ");
					scanf("%d", &filTemp);
					imprimirLocalesPiso(&centroComercial, filTemp, col, 0);
					break;
				case 3:
					printf("ingrese el nombre del local a buscar ");
					scanf("%34s", nombre);
					buscarLocalNombre(&centroComercial, fil, col, nombre);
					break;
				case 4:
					modificarLocal(&centroComercial, fil, col);
					break;
				case 5:
					EliminarLocal(&centroComercial, fil, col);
					break;
			}		
		}
		else{
			printf("Por favor ingrese una opcion valida");
		}
	} while(opcion!= 0);
	
	for ( i = 0; i <= fil; i++){
		free(centroComercial[i]);
	}
	free(centroComercial);

	return ;
	}

int main(){
	menu();
}