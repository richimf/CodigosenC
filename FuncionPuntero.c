
#include <stdio.h>

// Podemos definir un puntero a una funcion, el cual recive dos ints y devuelte un int  c:
// si, definimos un puntero...
int (*miPunteroFuncion)(int,int);

// Y una funcion cualquiera /o.o/
int addInt(int n, int m){
	return n+m;
}

int main(){
	// Apuntamos a nuestra funcion   O.O!
	// a nuestro puntero "miPunteroFuncion" le asignamos la referencia a nuestra funcion
	miPunteroFuncion = &addInt; //"Puntero!, vigila a addInt()""

	// Ahora usamos la funcion pueee /o.o/
	int resultado = (*miPunteroFuncion)(3,5); // resultado = 8
	printf(" resultado = %d \n",resultado);

}