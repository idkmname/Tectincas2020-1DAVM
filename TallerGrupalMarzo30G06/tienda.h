#include<stdio.h>
#include<string.h>

enum tipoProducto{
	LEGUMBRES, ENLATADOS, CEREALES, DULCES
};

typedef struct producto{
	char nombre[20];
	int precio;
	int tipo;

	
}producto;


//Inicializa la matriz con valores estandar 
void inicializar(producto matriz[][4], int fil, int col);

//Agregar un producto a la matriz de un tipo definido
void agregarProducto( producto matriz[][4] );





