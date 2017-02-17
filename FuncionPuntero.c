
#include <stdio.h>

// Podemos definir un puntero a una funcion, el cual recive dos ints y devuelte un int  O_O
// si, definimos un puntero...
int (*miPunteroFuncion)(int,int);

// Y luego, una funcion cualquiera /o.o/
int addInt(int n, int m){
    return n+m;
}

int main(){
    // Apuntamos a nuestra funcion   O.O! ...
    // A nuestro puntero "miPunteroFuncion" le asignamos la referencia a nuestra funcion:
    miPunteroFuncion = &addInt; //"Puntero!, vigila a addInt()""

    // Ahora usamos la funcion pueee /o.o/
    int resultado = (*miPunteroFuncion)(3,5); 
    printf(" resultado = %d \n",resultado); // resultado = 8
}



