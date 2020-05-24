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
		printf("3. Ordenar pisos por capacidad en la bodega");
		printf("4. Buscar local comercial\n");
		printf("5. Modificar informacion de los locales\n");
		printf("6. Eliminar local comercial\n");
		printf("7. Guardar informacion actua\n");
		printf("8. Cargar datos de la ultima sesion\n");
		printf("9. Imprimir toda la informacion almacenada\n");
		printf("0. Salir del programa \n");
		printf("Opc: ");
		scanf("%d", &opcion);
		if ( opcion >= 0 && opcion <= 8 ){
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
					printf("que piso desea revisar ");
					scanf("%d", &filTemp);
					ordenarPiso(&centroComercial, filTemp, col);
					break;
				case 4:
					printf("ingrese el nombre del local a buscar ");
					scanf("%34s", nombre);
					buscarLocalNombre(&centroComercial, fil, col, nombre);
					break;
				case 5:
					modificarLocal(&centroComercial, fil, col);
					break;
				case 6:
					eliminarLocal(&centroComercial, fil, col);
					break;
				case 7:
					guardarInformacion(&centroComercial, fil, col);
					break;
				case 8:
					cargarInformacion(&centroComercial, fil, col);
					break;
				case 9:
					ImprimirTodo(&centroComercial, fil, col);
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