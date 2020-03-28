#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum meses{	
	ENERO, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, AGOSTO,
	SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE
};

typedef struct persona{
	char nombre[20];
	int dia ;
	int mes ;
	int anio ;
}persona;


//inicializa la matriz con personas
void inicializar(persona matriz[][5]);

//agregar un nuevo usuario a la matriz 
void ingresarUsuario(persona matriz[][5]);

//Muestra los datos de todas las personas que cumplan durante ese mes
void mostrarDatosMes(persona matriz[][5], int mes);

//esta funcion cuenta cuantas personas hay en un mes
int contar(persona matriz[][5], int mes, int i);

//imprimir a las personas registradas segun su signo zodiacal 
void mostarRegistros(persona matriz[][5]);
