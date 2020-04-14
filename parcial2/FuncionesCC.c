#include "FuncionesCC.h"

void definirTamanio(local_t *** centroComercial, int fil, int col){
	int i, j, ids = 1;
	local_t **temp;
	
	temp = (local_t**) malloc(sizeof(local_t*)*fil);
	for ( i = 0; i <= fil; i++){
		temp[i] = (local_t*) malloc(sizeof(local_t)*col);
	}
	for ( i = 0; i < fil; i++){
		for ( j = 0; j < col; j++){
			temp[i][j].idLocal = ids++;
			temp[i][j].pisoLocal = 0;
			temp[i][j].numLocalxPiso = 0;
			temp[i][j].disp = vacio; 
		}
	}
	*centroComercial = temp;
}

void agregarNegocio(local_t *** centroComercial, int fil, int col){
	int piso, local, flag = 1;
	local_t **temp = *centroComercial;
	
	while (flag){
		printf("Ingrese el piso en el que desea poner el Negocio: ");
		scanf("%d", &piso);
		printf("Ingrese el numero de local en el que desea poner el Negocio: ");
		scanf("%d", &local);
		printf("");
		piso -=1;
		local -=1;
		if ( (piso > fil) || (local > col) ){
			printf("El lugar ingresado no existe en el centro comercial \n");
		}
		else if (temp[piso][local].disp == 1){		
			printf("El local esta ocupado \n");
		}
		else{
			flag = 0; 
		}
	}
	printf("Ingrese el nombre del Negocio ");
	scanf("%34s", temp[piso][local].nombreLocal );
	temp[piso][local].pisoLocal = piso + 1 ;
	temp[piso][local].numLocalxPiso = local + 1;
	temp[piso][local].disp = ocupado;
	*centroComercial = temp;
}

void imprimirLocalesPiso(local_t *** centroComercial, int filTemp, int col, int i){
	local_t **temp = *centroComercial;
	if( i > col ){
		return;
	}
	else{
		if( temp[filTemp - 1][i].disp ){
			printf("\nNombre del negocio: %s\n", temp[filTemp - 1][i].nombreLocal );
			printf("Id del negocio: %d\n", temp[filTemp - 1][i].idLocal );
			printf("Piso del negocio: %d\n", filTemp );
			printf("Numero del negocio: %d\n", i + 1);	
		}
		imprimirLocalesPiso(centroComercial, filTemp, col, i + 1);
	}
}

void buscarLocalNombre(local_t *** centroComercial, int fil, int col, char nombre[35]){
	int i, j;
	local_t **temp = *centroComercial;
	for ( i = 0; i < fil; i++){
		for ( j = 0; j < col; j++){
			if ( !(strcmp(temp[i][j].nombreLocal, nombre))){
				printf("\nEl Negocio %s ", temp[i][j].nombreLocal);
				printf("se encuentra en el piso %d ",i + 1);
				printf("en el local numero %d ", j + 1);
				printf("/n[id del local %d]",temp[i][j].idLocal);
				return;
			}
		}
	}
}

void modificarLocal(local_t *** centroComercial,int fil,int col){
	int i, j;
	char nombre[35];
	local_t **temp = *centroComercial;
	
	printf ("\ningrese el nombre del local que desea cambiar");
	scanf("%34s", nombre);
	buscarLocalNombre(&temp, fil, col, nombre);
	for ( i = 0; i < fil; i++){
		for ( j = 0; j < col; j++){
			if ( !(strcmp(temp[i][j].nombreLocal, nombre))){
				printf ("ingrese el nuevo nombre del local");
				scanf("%34s", nombre);
				strcpy(temp[i][j].nombreLocal, nombre);
				*centroComercial = temp;
				return;
			}
		}
	}
}

void EliminarLocal(local_t *** centroComercial,int fil,int col){
	int conf;
	char nombre[35];
	local_t **temp = *centroComercial;
	
	printf ("\ningrese el nombre del local que desea eliminar ");
	scanf("%34s", nombre);
	buscarLocalNombre(&temp, fil, col, nombre);
	printf("esta seguro que desea borrar este local? \n");
	printf(" 1 = si, 0 = no \n");
	scanf("%d", &conf);
	if (conf){	
		int i, j;
		for ( i = 0; i < fil; i++){
			for ( j = 0; j < col; j++){
				if ( !(strcmp(temp[i][j].nombreLocal, nombre))){
					strcpy(temp[i][j].nombreLocal, "");
					temp[i][j].disp = vacio;
					printf("Local borrado con exito");
					*centroComercial = temp;
					return;
				}
			}
		}
	}
}