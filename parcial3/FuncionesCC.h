/*#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_*/
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define FILENAME "Locales2"

//Local 
typedef struct Local{
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numLocalxPiso;//Columnas
	int disp;// 0 si esta vacio, 1 si esta ocupado
	int espacioBodega;// el espacio en metros cubicos que tiene disponible un local
	char nombreLocal[35];
	char tipoLocal[30];
} local_t;

//enums de disponibilidad
enum disp{
	vacio, ocupado	
};

/* Define el tamano del la matriz en la que se contiene el centro comercial*/
void definirTamanio(local_t *** centroComercial, int fil, int col);

/* Imprime en consola la informacion de un negocio */
void mostrarInformacion(local_t *** centroComercial, int piso, int local);

/* Agrega un nuevo Negocio al centro comercial */
void agregarNegocio(local_t *** centroComercial, int fil, int col);

/*Muestra en pantalla la informacion de todos los locales en el piso*/ 
void imprimirLocalesPiso(local_t *** centroComercial, int filTemp, int col, int i);

/*ordena los locales en un piso segun el tamaño de la bodega*/
void ordenarPiso(local_t *** centroComercial, int filTemp, int col);

/*Imprime el lugar en el que se encuentra un local */
void buscarLocalNombre(local_t *** centsroComercial, int fil, int col, char nombre[35]);

/*Permite cambiar el nombre de un local*/
void modificarLocal(local_t *** centroComercial, int fil, int col);

/*Elimina un local del sistema, borrando el nombre y cambiando su 
disponibilidad a vacio*/
void eliminarLocal(local_t *** centroComercial, int fil, int col);

/* guarda en un archivo la informacion del centro comercial */
void guardarInformacion(local_t *** centroComercial, int fil, int col);

/*carga la ultima informacion guardadada*/
void cargarInformacion(local_t *** centroComercial, int fil, int col);

/*Imprime todos los elementos en la matriz independiente de su contenido*/
void ImprimirTodo(local_t *** centroComercial, int fil, int col);
/*#endif  FUNCIONESCC_H_ */

/*funcion estandar quicksort, para ordenar una final segun el espacio en la bodega*/
void qs(local_t lista[],int limite_izq,int limite_der);


/*Intercambia la posicion de dos locales en una misma fila*/
void swap(local_t *** centroComercial, int registro1, int registro2, int fil);