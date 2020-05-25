#include "FuncionesCC.cpp"
#include <stdio.h>

void menu(){
	int fil, col, opcion, filTemp, i;
	local_t ** centroComercial;
	char nombre[35];
	
	try{ 
		printf("Ingrese la cantidad de pisos en su centro comercial: ");
		scanf("%d", &fil);
	
		if (fil > LIMITEMAX){
			fil = LIMITEMAX;
			throw (1);
		}
	}
	catch(...){
		printf("\nEl centro comercial no puede tener mas de %d pisos; ",LIMITEMAX);
		printf("se ha establecido en %d pisos", LIMITEMAX );
	}
	
	try{
		printf("\nIngrese la cantidad de locales en cada piso de su centro comercial: ");
		fflush(stdin);
		scanf("%d", &col);

		if (fil > LIMITEMAX){
			fil = LIMITEMAX;
			throw (1);
		}
	}
	catch(...){
		printf("\nEl centro comercial no puede tener mas de %d locales; ",LIMITEMAX);
		printf("se ha establecido en %d locales", LIMITEMAX );
	}

	fil -= 1;
	col -= 1;
	definirTamanio(&centroComercial, fil, col);
	
	do {
		printf("\nOpciones para centro comercial: \n\n");
		printf("1. Agregar local comercial\n");
		printf("2. Mostrar locales por piso\n");
		printf("3. Ordenar pisos por capacidad en la bodega\n");
		printf("4. Ordenar pisos segun la cantidad de empleados contratados\n");
		printf("5. Buscar local comercial\n");
		printf("6. Modificar informacion de los locales\n");
		printf("7. Eliminar local comercial\n");
		printf("8. Ordenar la matriz segun el id de los locales\n");
		printf("9. Ordenar la matriz segun la el costo de los locales\n");
		printf("10. Guardar informacion actua\n");
		printf("11. Cargar datos de la ultima sesion\n");
		printf("12. Imprimir toda la informacion almacenada\n");
		printf("0. Salir del programa \n");
		printf("Opc: ");
		fflush(stdin);
		scanf("%d", &opcion);
		if ( opcion >= 0 && opcion <= 12 ){
			switch (opcion) {
				case 1:
					agregarNegocio(&centroComercial, fil, col);
					break;	
				case 2:
					printf("Que piso desea revisar ");
					fflush(stdin);
					scanf("%d", &filTemp);
					if (filTemp <= fil && filTemp > 0){
						imprimirLocalesPiso(&centroComercial, filTemp, col, 0);
					}
					else{
						printf("El centro comercial no cuenta con el piso ingresado");
					}
					break;
				case 3:
					printf("que piso desea ordenar ");
					fflush(stdin);
					scanf("%d", &filTemp);
					if (filTemp <= fil && filTemp > 0){
						ordenarPiso(&centroComercial, filTemp - 1, col);
					}
					else{
						printf("El centro comercial no cuenta con el piso ingresado");
					}
					break;
				case 4: 
					printf("que piso desea ordenar ");
					fflush(stdin);
					scanf("%d", &filTemp);
					if (filTemp <= fil && filTemp > 0){
						ordenarEmpleados(&centroComercial, filTemp - 1, col);
					}
					else{
						printf("El centro comercial no cuenta con el piso ingresado");
					}
					break;
				case 5:
					printf("ingrese el nombre del local a buscar ");
					fflush(stdin);
					scanf("%34s", nombre);
					buscarLocalNombre(&centroComercial, fil, col, nombre);
					break;
				case 6:
					modificarLocal(&centroComercial, fil, col);
					break;
				case 7:
					eliminarLocal(&centroComercial, fil, col);
					break;
				case 8:
					break;
				case 9:
					break;
				case 10:
					guardarInformacion(&centroComercial, fil, col);
					break;
				case 11:
					cargarInformacion(&centroComercial, fil, col);
					break;
				case 12:
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