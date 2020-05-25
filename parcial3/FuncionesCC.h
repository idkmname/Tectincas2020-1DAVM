/*#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_*/
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define FILENAME "Locales2"
#define  LIMITEMAX 60
#include <iostream>

//Local 
typedef struct Local{
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numLocalxPiso;//Columnas
	int espacioBodega;// el espacio en metros cubicos que tiene disponible un local
	int disp;// 0 si esta vacio, 1 si esta ocupado
	int empleados;// representa le numero de empleados contratados por el local
	int costoLocal; //representa en dolares cuanto cuesta el alquiler del local
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

/*Ordena los locales en un piso segun la cantidad de empleados contratados*/
void ordenarEmpleados(local_t *** centroComercial, int filTemp, int col);

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

/*funcion estandar mergesort, para ordenar una filas segun los empleados*/
void mergesort(local_t a[],int i,int j, int col);

/*funcion merge estandar, para ordenar una fila segun el numero de empleados*/
void merge(local_t a[],int i1,int j1,int i2,int j2,int col);

/*Seleccion sort para ordenar la matriz segun el id de los locales*/
void selection_sort(local_t ***centroComercial, int fil, int col);

/*Funcion para insertar un elemento en en una lista+*/
void insertion(local_t *lista, local_t item, int size, int pos);

/*ordena los locales en la matriz segun el costo de alquiler*/
void insertionSort(local_t *** centroComercial , int col, int fil );

/*++funcion de insertion: la funcion de insertion es una funcion
especializada para el correcto procedimiento del insertion sort,
la cual recibe el arreglo auxiliar al cual se le insertara, asi como
el numero de elementos totales que hay en el arreglo y el elemento 
a insertar asi como la posicion en la cual se insertara.*/

