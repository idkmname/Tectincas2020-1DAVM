#include "SERFunciones.c"



void mostrarMenu() {
	int opcion = 0, mes, estacion;
	
	persona matriz[12][5];
	
	inicializar(matriz);
	do {
		printf("Opciones \n\n");
		printf("1. Ingresar un nuevo usuario\n");
		printf("2. Mostrar cumpleanios por mes\n");
		printf("3. Mostrar numero de usuarios por mes\n");
		printf("4. Mostrar usuarios ingresados segun la estacion\n");
		printf("0. Salir\n\n");
		printf("Opc: ");
		scanf("%d", &opcion);
		switch (opcion) {
			case 1:
				ingresarUsuario(matriz);
				break;
			case 2:
				printf("Ingrese el mes del cual desea conocer los datos de los individuos: ");
				scanf("%d", &mes);				
				mostrarDatosMes(matriz, mes);
				break;
			case 3:
				printf ("Ingrese el mes que desea revisar: ");
				scanf("%d", &mes);
				mes -= 1;
				printf("%d\n",contar(matriz, mes, 0));
				break;
			case 4:
				printf ("Que estacion quiere revisar ?")						
				printf("1. Invierno");
				printf("2. Primavera");
				printf("3. Verano");
				printf("4. Otoño");
				scanf("/d", &estacion)
				estaciones(matriz, estacion);
				break;
		}
		//Cuando el usuario ingrese 0 se terminará el menu
	} while(opcion!=0);
}

int main(){
	//Menu que muestra las opciones disponibles
	mostrarMenu ();
	return 0;
}