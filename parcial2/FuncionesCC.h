/*#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_*/
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Local 
typedef struct Local{
	char nombreLocal[35];
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numLocalxPiso;//Columnas
	int disp;// 0 si esta vacio, 1 si esta ocupado
	// Completelo con lo que quiera
} local_t;

//enums de disponibilidad
enum disp{
	vacio, ocupado	
};

/* Define el tamano del la matriz en la que se contiene el centro comercial*/
void definirTamanio(local_t *** centroComercial, int fil, int col);


/* Agrega un nuevo Negocio al centro comercial */
void agregarNegocio(local_t *** centroComercial, int fil, int col);


/*Muestra en pantalla la informacion de todos los locales en el piso*/ 
void imprimirLocalesPiso(local_t *** centroComercial, int filTemp, int col, int i);

/*Imprime el lugar en el que se encuentra un local */
void buscarLocalNombre(local_t *** centroComercial, int fil, int col, char nombre[35]);

/*Permite cambiar el nombre de un local*/
void modificarLocal(local_t *** centroComercial,int fil,int col);

/*Elimina un local del sistema, borrando el nombre y cambiando su 
disponibilidad a vacio*/
void EliminarLocal(local_t *** centroComercial,int fil,int col);

/*#endif  FUNCIONESCC_H_ */