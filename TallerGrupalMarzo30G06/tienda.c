#include "tienda.h"
	
void inicializar(producto matriz[][4], int fil, int col){
	int i, j;
	char emptyNom[20] = "";

	for ( i = 0; i < fil; i++){
		for ( j = 0; j < col; j++){
			strcpy(matriz[i][j].nombre, emptyNom);
			matriz[i][j].precio = 0;
			matriz[i][j].tipo = 0;
		}
	}
}

void venderProducto(producto matriz[][4], int fil, int col){
	int i, j, flag;
	char producto[20];
	
	printf(" que producto desea comprar: ");
	scanf(" %s ", producto);
	
	for ( i = 0; i < fil; i++){
		for ( j = 0; j < col; j++){
			if ( !strcmp( producto, matriz[i][j].nombre ) ){
				flag = 1;
				printf("\n producto %d \n", matriz[i][j].precio);
				printf("\n precio del producto: %d \n", matriz[i][j].precio);
				switch (matriz[i][j].tipo){
					
					case LEGUMBRES:
						printf(" tipo del producto: Dulces \n" );
						break;
						
					case ENLATADOS:
						printf(" tipo del producto: Dulces \n" );
						break; 

					case CEREALES:
						printf(" tipo del producto: Dulces \n" );
						break;				

					case DULCES:
						printf(" tipo del producto: Dulces \n" );
						break;
				}
			}				
		}
	}	
	if (flag != 1)
		printf("no hay de esos productos en la tienda");
}


int menu(){
   int opc;
	printf( "\n MENU \n" );
	printf( " 1 INGRESAR PRODUCTO \n" );
	printf( "2 \n" );
	printf( "3 \n" );
	printf( "0 SALIR \n" );
	scanf( "%d", &opc );
   return opc;
}

void agregarProducto( producto matriz[4][4] ){
   int j,i;
      

   for( i = 0; i < 4; i++ ){
	

   }

}