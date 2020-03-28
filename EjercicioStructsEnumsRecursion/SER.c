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
		printf("4. Mostrar el numero de usuarios registrados\n");
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
				mostarRegistros(matriz);
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