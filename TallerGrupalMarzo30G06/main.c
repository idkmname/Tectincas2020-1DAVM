#include "tienda.c"

int main(){
   int opc;
   
   producto matriz[4][4];
  
   do{
      opc = menu();
		switch(opc){   
			case 1: agregarProducto(matriz);
				break;
			case 2: break;

			case 3: break;
		}
   }
   while( opc != 0 );
   return;

}