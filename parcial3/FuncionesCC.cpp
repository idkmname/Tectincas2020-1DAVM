#include "FuncionesCC.h"

void definirTamanio(local_t *** centroComercial, int fil, int col){
	local_t **temp;
	try{
		if ((temp = (local_t**) malloc( sizeof(local_t*) * (fil + 1) )) != NULL ){
			int i, j, ids = 1;
			for ( i = 0; i <= fil; i++){
				if((temp[i] = (local_t *) malloc( sizeof(local_t) * (col + 1) )) == NULL ){
					throw(4);
				}
			}
			for ( i = 0; i <= fil; i++){
				for ( j = 0; j <= col; j++){
					temp[i][j].idLocal = ids++;
					temp[i][j].pisoLocal = 0;
					temp[i][j].numLocalxPiso = j;
					temp[i][j].disp = vacio;
					temp[i][j].costoLocal = VALORBASE;
				}
			}
			*centroComercial = temp;
		}
		else{
			throw(4);
		}
	}
	catch(...){
		printf("No se pudo reservar suficiente memoria para crear el centro comercial");
	}
}

void mostrarInformacion(local_t *** centroComercial, int piso, int local){
	local_t **temp = *centroComercial;
	printf("\nEl Negocio %s ", temp[piso][local].nombreLocal);
	printf("se encuentra en el piso %d ",piso + 1);
	printf("en el local numero %d ", local + 1);
	printf("\n[id del local %d]",temp[piso][local].idLocal);
	printf("[Tipo: %s]",temp[piso][local].tipoLocal);
	printf("[Capacidad en bodega: %d]",temp[piso][local].espacioBodega);
	printf("[Empleados: %d]", temp[piso][local].empleados);
	printf("[costo alquiler: %d]", temp[piso][local].costoLocal);
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
		fflush(stdin);
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
	fflush(stdin);
	try{
		if (scanf("%34s", temp[piso][local].nombreLocal ) > 34){
			throw (2);
		}  
	}
	catch(int fail){
		printf("se ha establecido el nombre del negocio como %s\n", temp[piso][local].nombreLocal);
	}
	printf("Ingrese de que tipo es su Negocio\ntipo: ");
	fflush(stdin);
	try{
		if (scanf("%29s", temp[piso][local].tipoLocal ) > 29);
			throw(2);
	}
	catch(int fail){
		printf("se ha establecido el tipo del negocio como %s\n", temp[piso][local].tipoLocal);
	}
	printf("Cuantos empleados tendra su local\nempleados: ");
	fflush(stdin);
	scanf("%d", &temp[piso][local].empleados);
	temp[piso][local].espacioBodega = 10;
	temp[piso][local].pisoLocal = piso + 1;
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
	qs(temp[filTemp], 0, col-1);
}

void ordenarEmpleados(local_t *** centroComercial, int filTemp, int col){
	local_t **temp = *centroComercial;
	mergesort(temp[filTemp], 0, col-1, col);
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
	int i, j, opc;
	char nombre[35];
	local_t **temp = *centroComercial;
	
	printf ("\ningrese el nombre del local que desea cambiar\nnombre: ");
	fflush(stdin);
	scanf("%34s", nombre);
	for ( i = 0; i <= fil; i++){
		for ( j = 0; j <= col; j++){
			if ( !(strcmp(temp[i][j].nombreLocal, nombre))){
				mostrarInformacion(centroComercial, i, j);
				do{
					printf("\n1. Cambiar el nombre del local ");
					printf("\n2. Cambiar el tipo del local");
					printf("\n3. Cambiar la capacidad de la bodega");
					printf("\n4. Cambiar el numero de empleados actuales");
					printf("\n5. Cambiar el costo de alquiler para el local");
					printf("\n0.Volver al menu principal\n");
					fflush(stdin);
					scanf("%d",&opc);

					switch (opc){
					case 1:
						printf ("\ningrese el nuevo nombre del local\nnombre: ");
						fflush(stdin);
						scanf("%34s", temp[i][j].nombreLocal);
						break;
					case 2:
						printf ("\ningrese el nuevo Tipo del local\ntipo: ");
						fflush(stdin);
						scanf("%29s", temp[i][j].tipoLocal);
						break;
					case 3:
						printf("\ningrese la nueva capacidad en la bodega\ncapacidad: ");
						fflush(stdin);
						scanf("%d", &temp[i][j].espacioBodega);
						break;
					case 4:
						printf("\nIngrese el nuevo numero de empleados\n empleados: ");
						fflush(stdin);
						scanf("%d", &temp[i][j].empleados);
					case 5:
						printf("\ningrese El nuevo costo del local\n costo: ");
						fflush(stdin);
						scanf("%d", &temp[i][j].costoLocal);
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
	fflush(stdin);
	scanf("%34s", nombre);
	buscarLocalNombre(&temp, fil, col, nombre);
	printf("esta seguro que desea borrar este local? \n");
	printf(" 1 = si, 0 = no \n");
	fflush(stdin);
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
	int i, j, confirmacion, flag = 0;
	do{
		if (flag){
			printf("por favor ingrese una opcion valida");
		}
		printf("\nesta seguro de que desea sobreescribir los datos guardados?");
		printf("\n 1.si, 2.no\n");
		fflush(stdin);
		scanf("%d", &confirmacion);
		flag = 1;
	}while((confirmacion != 1) && (confirmacion !=2));
	if (confirmacion == 1){
		FILE *f = fopen( FILENAME , "w" );
		fwrite(&fil, sizeof(int), 1, f);
		fwrite(&col, sizeof(int), 1, f);
		for (i = 0; i <= fil; i++){
			for (j = 0; j <= col; j++){
				fwrite(&temp[i][j], sizeof(local_t), 1, f);
			}
		}
		fclose(f);
		printf("los datos fueron guardados correctamente");
	}
	else{
		printf("los datos no han sido guardados");
	}
}

void cargarInformacion(local_t *** centroComercial, int fil, int col){
	local_t **temp = *centroComercial;
	int i, ultimaFil, ultimaCol, j, ids = 1;
	FILE *f ;
	if ((f = fopen( FILENAME , "r" )) != NULL){
		fread(&ultimaFil, sizeof(int), 1,f);
		fread(&ultimaCol, sizeof(int), 1,f);
		if ( (ultimaFil > fil) || (ultimaCol > col) ){
			printf( "El centro comercial no es capaz de almacenar los datos ingresados " );
			printf( "anteriormente; es imposible cargar la informacion" );
		}
		else{
			for (i = 0; i <= ultimaFil; i++){
				for (j = 0; j <= ultimaCol; j++){
					fread(&temp[i][j], sizeof(local_t), 1, f);
				}
			}
			for (i = 0; i <= ultimaFil; i++){
				for (j = 0; j <= ultimaCol; j++){
					temp[i][j].idLocal = ids++;
				}
			}
			printf("\nla informacion se cargo correctamente\n");
		}
	}
	else{
		printf("no se encontro ningun archivo que pueda ser cargado");
	}
	fclose(f);
	
}

void imprimirTodo(local_t *** centroComercial, int fil, int col){
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

void mergesort(local_t a[],int i,int j, int col){
	int mid;
	if(i<j)
	{
		mid=(i+j)/2;
		mergesort(a,i,mid,col);		
		mergesort(a,mid+1,j,col);
		merge(a,i,mid,mid+1,j,col);	
	}
}
 
void merge(local_t a[],int i1,int j1,int i2,int j2,int col){
	//local_t *temp = calloc(col, sizeof(local_t));//array used for merging
	local_t temp[50];
	int i,j,k;
	i=i1;	//beginning of the first list
	j=i2;	//beginning of the second list
	k=0;
	
	while(i<=j1 && j<=j2){	//while elements in both list
		if(a[i].empleados<a[j].empleados)
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	
	while(i<=j1)	//copy remaining elements of the first list
		temp[k++]=a[i++];
		
	while(j<=j2)	//copy remaining elements of the second list
		temp[k++]=a[j++];
		
	//Transfer elements from temp[] back to a[]
	for(i=i1,j=0;i<=j2;i++,j++){
		a[i]=temp[j];
	}
	//free(temp);
}

void selection_sort(local_t ***centroComercial, int fil, int col){
	local_t **temp = *centroComercial, auxiliar;
	int i, j, k, l, actual, menorFil, menorCol;
	for (i = 0; i <= fil; i++){
		for(j = 0; j <= col; j++){
			menorFil = i;
			menorCol = j;
			actual = j;
			for (k = i; k <= fil; k++){
				for (l = actual; l <= col; l++){
					if (temp[k][l].idLocal < temp[menorFil][menorCol].idLocal){
						menorFil = k;
						menorCol = l;
					}
				}
				actual = 0;
			}
			auxiliar = temp[i][j];
			temp[i][j] = temp[menorFil][menorCol];
			temp[menorFil][menorCol] = auxiliar;
		}
	}
}

void insertion(local_t *lista, local_t item, int size, int pos){
	int i;
	for (i = size; i >= pos; i--){
		lista[i] = lista[i-1];
	}
	lista[pos] = item;
}

void insertionSort(local_t *** centroComercial , int fil, int col ){ 
	local_t **temp = *centroComercial;
    int i, j, size, k, flag, elementos;
	local_t *ordenado;
	size = 0;
	try{
		if ((ordenado = (local_t*) malloc(sizeof(local_t) * ((col+1)*(fil+1))))== NULL ){
			throw(4);
		} 
		for (i = 0; i <= fil; i++){
			for (j = 0; j <= col; j++){
				if (size == 0){
					ordenado[size] = temp[i][j];
					size++;
				}
				else{
					flag = 1;
					for (k = 0; k < size; k++){
						if(temp[i][j].costoLocal < ordenado[k].costoLocal){
							insertion(ordenado, temp[i][j], size, k);
							size++;
							k = size;
							flag = 0;
						}
					}
					if (flag){
						ordenado[size] = temp[i][j];
						size++;
					}
				}
			}
		}
		size = 0 ;
		for (i = 0; i <= fil; i++){
			for (j = 0; j <= col; j++){
				temp[i][j] = ordenado[size++];
			}
		}
	}
	catch(...){
		printf("No hay recursos suficientes para realizar esta operacion");
	}
} 
