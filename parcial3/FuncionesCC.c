#include "FuncionesCC.h"

void definirTamanio(local_t *** centroComercial, int fil, int col){
	int i, j, ids = 1;
	local_t **temp;
	
	temp = (local_t**) malloc(sizeof(local_t*)*fil);
	for ( i = 0; i <= fil; i++){
		temp[i] = (local_t*) malloc(sizeof(local_t)*col);
	}
	for ( i = 0; i <= fil; i++){
		for ( j = 0; j <= col; j++){
			temp[i][j].idLocal = ids++;
			temp[i][j].pisoLocal = 0;
			temp[i][j].numLocalxPiso = j;
			temp[i][j].disp = vacio; 
			temp[i][j].espacioBodega = 20;
		}
	}
	*centroComercial = temp;
}

void mostrarInformacion(local_t *** centroComercial, int piso, int local){
	local_t **temp = *centroComercial;
	printf("\nEl Negocio %s ", temp[piso][local].nombreLocal);
	printf("se encuentra en el piso %d ",piso + 1);
	printf("en el local numero %d ", local + 1);
	printf("\n[id del local %d]",temp[piso][local].idLocal);
	printf("[Tipo: %s]",temp[piso][local].tipoLocal);
	printf("[Capacidad en bodega: %d]",temp[piso][local].espacioBodega);
	if (temp[piso][local].disp){
		printf("[disponibilidad = Ocupado]\n");
	}
	else{
		printf("[disponibilidad = Vacio]\n");
	}
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
		else if (temp[piso][local].disp){		
			printf("El local esta ocupado \n");
		}
		else{
			flag = 0; 
		}
	}

	printf("Ingrese el nombre del Negocio\nnombre: ");
	scanf("%34s", temp[piso][local].nombreLocal );
	printf("Ingrese de que tipo es su Negocio\ntipo: ");
	scanf("%29s", temp[piso][local].tipoLocal );
	temp[piso][local].pisoLocal = piso + 1 ;
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
			mostrarInformacion(centroComercial, filTemp - 1, i);
		}
		imprimirLocalesPiso(centroComercial, filTemp, col, i + 1);
	}
}

void ordenarPiso(local_t *** centroComercial, int filTemp, int col){
	local_t **temp = *centroComercial;
	qs(temp[filTemp],0,col-1);
}

void buscarLocalNombre(local_t *** centroComercial, int fil, int col, char nombre[35]){
	int i, j;
	local_t **temp = *centroComercial;
	for ( i = 0; i <= fil; i++){
		for ( j = 0; j <= col; j++){
			if ( !(strcmp(temp[i][j].nombreLocal, nombre))){
				mostrarInformacion(centroComercial, i, j);
				return;
			}
		}
	}
}


void modificarLocal(local_t *** centroComercial,int fil,int col){
	int i, j, bodega, opc;
	char nombre[35], tipo[30];
	local_t **temp = *centroComercial;
	
	printf ("\ningrese el nombre del local que desea cambiar\nnombre: ");
	scanf("%34s", nombre);
	buscarLocalNombre(&temp, fil, col, nombre);
	for ( i = 0; i < fil; i++){
		for ( j = 0; j < col; j++){
			if ( !(strcmp(temp[i][j].nombreLocal, nombre))){
				do{
					printf("\n1.Cambiar el nombre del local ");
					printf("\n2.Cambiar el tipo del local");
					printf("\n3.Cambiar la capacidad de la bodega");
					printf("\n0.Volver al menu principal\n");
					scanf("%d",&opc);

					switch (opc){
					case 1:
						printf ("\ningrese el nuevo nombre del local\nnombre: ");
						scanf("%34s", temp[i][j].nombreLocal);
						break;
					case 2:
						printf ("\ningrese el nuevo Tipo del local\ntipo: ");
						scanf("%29s", temp[i][j].tipoLocal);
						break;
					case 3:
						printf("\ningrese la nueva capacidad en la bodega\ncapacidad: ");
						scanf("%d", &bodega);
						break;
					case 0:
						break;
					default:
						printf("por favor ingrese una opcion valida");
						break;
					}
				}while (opc);
				*centroComercial = temp;
				return;
			}
		}
	}
	printf("No existe un local con el nombre consultado\n");
}

void eliminarLocal(local_t *** centroComercial,int fil,int col){
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

void guardarInformacion(local_t *** centroComercial, int fil, int col){
	local_t **temp = *centroComercial;
	int i, j;
	FILE *f;
	f = fopen( FILENAME , "w" ); 
	/*
	fwrite(&fil, sizeof(int), 1, f);
	fwrite(&col, sizeof(int), 1, f);
	for (i = 0; i <= fil; i++){
		for (j = 0; j <= col; j++){
			mostrarInformacion(centroComercial, i, j);
			fwrite(&temp[i][j], sizeof(local_t), 1, f);
		}
	}
	*/
	fclose(f);

}

void cargarInformacion(local_t *** centroComercial, int fil, int col){
	local_t **temp = *centroComercial;
	int i, ultimaFil, ultimaCol, j;
	FILE *f = fopen( FILENAME , "r" );
	fread(&ultimaFil, sizeof(int), 1,f);
	fread(&ultimaCol, sizeof(int), 1,f);
	if ( (ultimaFil > fil) || (ultimaCol > col) ){
		printf( "El tamaño del centro comercial no coincide con el ingresado\n" );
		printf( "anteriormente, es imposible cargar la informacion" );
	}
	else{
		for (i = 0; i <= fil; i++){
			for (j = 0; j <= col; j++){
				fread(&temp[i][j], sizeof(local_t), 1, f);
			}
		}
	}
	fclose(f);
	
}

void ImprimirTodo(local_t *** centroComercial, int fil, int col){
	local_t **temp = *centroComercial;
	int i,j;
	for (i = 0; i <= fil; i++){
		for (j = 0; j <= col; j++){
			mostrarInformacion(centroComercial, i, j);
		}
	}
}


void qs(local_t lista[],int limite_izq,int limite_der){
    int izq,der,pivote;
	local_t temporal;
    izq=limite_izq;
    der = limite_der;
    pivote = lista[(izq+der)/2].espacioBodega;

    do{
        while(lista[izq].espacioBodega<pivote && izq<limite_der)izq++;
        while(pivote<lista[der].espacioBodega && der > limite_izq)der--;
        if(izq <=der)
        {
				
            temporal = lista[izq];
            lista[izq]=lista[der];
            lista[der]=temporal;
            izq++;
            der--;

        }

    }while(izq<=der);
    if(limite_izq<der){qs(lista,limite_izq,der);}
    if(limite_der>izq){qs(lista,izq,limite_der);}
}

void swap(local_t *** centroComercial, int registro1, int registro2, int fil){
	local_t **temp = *centroComercial;
	local_t auxiliar;
	auxiliar = temp[fil][registro1];
	temp[fil][registro1] = temp[fil][registro2];
	temp[fil][registro1] = auxiliar;
}