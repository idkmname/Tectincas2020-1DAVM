#include "SER.h"

void inicializar(persona matriz[][5]){
	persona prototipo;
	int i, j;
	char emptyNom[20] = "";
	
	for ( i = 0; i < 12; i++){
		for ( j = 0; j < 5; j++){
			matriz[i][j] = prototipo;
			strcpy(matriz[i][j].nombre, emptyNom);
			matriz[i][j].mes = 0;
			matriz[i][j].dia = 0;
			matriz[i][j].anio = 0;
		}
	}
}


void ingresarUsuario(persona matriz[][5]){
	int mes, col;
	persona nuevoUsuario;
	
	printf("ingrese el mes de nacimiento ");
	scanf("%d", &mes );
	mes -=1;
	col = contar(matriz, mes,0);
	
	if (col < 5){
		matriz[mes][col].mes = mes + 1;
		printf("Ingrese el nombre: ");
		scanf("%s", matriz[mes][col].nombre);
		printf("Ingrese el dia de nacimiento:");
		scanf("%d", &matriz[mes][col].dia);
		printf("Ingrese el año de nacimiento");
		scanf("%d", &matriz[mes][col].anio);
	}
	else
		printf("El mes ingresado esta lleno");
}


void mostrarDatosMes( persona matriz[][5], mes ){
	int j = 0;
	char temp[20] = "";
	mes -= 1;
	if (mes >= 0 && mes < 12){	
		do{
			if ( strcmp(matriz[mes][j].nombre, temp) ){
				printf("\nNombre: %s", matriz[mes][j].nombre);
				printf("\nDia de nacimiento: %d\n", matriz[mes][j].dia);
				printf("Mes de nacimiento: %d\n", matriz[mes][j].mes);
				printf("Anio de nacimiento: %d\n", matriz[mes][j].anio);	
			}
			j++;
		}while(j!=4);
	}else{
		printf("No ha ingresado un mes valido");
	}
	return;
}

int contar(persona matriz[][5], int mes, int i ){
	char temp[20] = "";
	
	//printf("i %d, mes %d, nom%s--\n", i , mes ,matriz[mes][i].nombre );
	
	if ( !strcmp(matriz[mes][i].nombre, temp) ){
		return i;
	}
	else{
		if ( i < 4)
			return contar(matriz, mes, i + 1);
		else
			return i;
	}
}


void estaciones(persona matriz[][5], int estacion){
	switch(estacion)
	case 1: 
		printf("Hemisferio norte: \n")
		mostrarDatosMes(matriz, DICIEMBRE);
		mostrarDatosMes(matriz, ENERO);
		mostrarDatosMes(matriz, FEBRERO);
		
		printf("Hemisferio sur: \n")
		mostrarDatosMes(matriz, JUNIO);
		mostrarDatosMes(matriz, JULIO);
		mostrarDatosMes(matriz, AGOSTO);

	case 2:
		
		printf("Hemisferio norte: \n")
		mostrarDatosMes(matriz, MARZO);
		mostrarDatosMes(matriz, ABRIL);
		mostrarDatosMes(matriz, MAYO);
	
		printf("Hemisferio sur: \n")
		mostrarDatosMes(matriz, OCTUBRE);
		mostrarDatosMes(matriz, SEPTIEMBRE);
		mostrarDatosMes(matriz, NOVIEMBRE);
		
	case 3:
		printf("Hemisferio norte: \n")
		mostrarDatosMes(matriz, JUNIO);
		mostrarDatosMes(matriz, JULIO);
		mostrarDatosMes(matriz, AGOSTO);
		
		printf("Hemisferio sur: \n")
		mostrarDatosMes(matriz, DICIEMBRE);
		mostrarDatosMes(matriz, ENERO);
		mostrarDatosMes(matriz, FEBRERO);
		
		
	if ( == 4):
		
		printf("Hemisferio norte: \n")
		mostrarDatosMes(matriz, OCTUBRE);
		mostrarDatosMes(matriz, SEPTIEMBRE);
		mostrarDatosMes(matriz, NOVIEMBRE);
		
		
		printf("Hemisferio SUR: \n")
		mostrarDatosMes(matriz, MARZO);
		mostrarDatosMes(matriz, ABRIL);
		mostrarDatosMes(matriz, MAYO);
	
}

















