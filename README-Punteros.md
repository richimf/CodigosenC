# PUNTEROS #

### QUE ES ###
* Un puntero es una variable que contiene una dirección de memoria.

* Así como una variable puede contener un número **b = 5**, esta variable contiene una dirección de memoria (son unos numeritos tipo 0x7fab5fbff4ad y siempre cambian).

* Ahora, esta dirección de memoria es la ubicación de un objeto (o variable) en la memoria, digamos que en ese lugar vive la  otra variable.
Entonces, si una variable **A** contiene la dirección de otra variable **B**, decimos que **A** apunta **B**. Esta variable **A** sera el puntero y para declarar un puntero lo hacemos así:

> tipo_de_dato *variable;

Ejemplo:
```C
int *puntero;
```

* Importante:

	- **Int** define el tipo de variable a la que el puntero puede apuntar, en este caso solo podremos apuntar a variables de tipo **Int**. El compilador asume que cualquier dirección que contenga apunta a un entero **Int**.

	- Aunque técnicamente no es obligatorio, en realidad **podriamos apuntar** a un tipo **Float** o **Char** (o cualquier otro), pero esto puede ocasionar errores, entonces debe hacerse con cuidado.


### OPERADORES ###

Los punteros utilizan dos operadores, estos son **&** y * .
* El operador **&** obtiene la dirección de memoria de una variable.
* El operador * hace dos cosas:

	- Define a una variable como puntero, ej: int *puntero; 
	
	- Lee el valor de un puntero (es decir, no la dirección, sino el valor).
	
Ejemplo:
```C
int variable = 15;
int *direccion = &variable; //un puntero guarda una direccion de memoria, con '&' extraemos la direccion de 'variable'
int valor = *direccion;     //el * sirve para leer el valor de 'direccion', este será 15
   
printf("\n variable = %d",variable);
printf("\n *direccion = %p",direccion);
printf("\n valor = %d",valor);
printf("\n valor de direccion = %d",*direccion);
```
La salida del programa seria:
```
variable = 15
*direccion = 0x7fff5fbff6cc
valor = 15
valor de direccion = 15
 ```

Veamos otro ejemplo:
En este código dos Punteros harán referencia al mismo objeto.
```C
int variable = 15;
int *puntero1;
int *puntero2;

puntero1 = &variable; //puntero1 guarda la direccion de variable
puntero2 = puntero1;  //puntero2 guarda la direccion que tiene puntero1

//Imprimir el valor que tiene cada puntero, para ello usamos * .
printf("puntero1 = %d, puntero2 = %d \n",*puntero1, *puntero2);

//Imprimir la direccion de cada puntero, un puntero ya es una direccion, entonces solo pon el nombre del puntero.
printf("puntero1 = %p, puntero2 = %p \n",puntero1, puntero2);
```
La salida del programa es:
```
puntero1 = 15, puntero2 = 15 
puntero1 = 0x7fff5fbff6cc, puntero2 = 0x7fff5fbff6cc 
```

### CONVERSIONES DE PUNTEROS ###

Los punteros pueden convertirse en otro tipo de puntero. Pero, como dijimos, se debe tener cuidado con el tipo de dato usado en el puntero. En este código se intentará pasar un **double** a **int**. 
```C
double x = 100.1, y;
int *p;
    
p = (int *)&x;
y = *p;
    
printf("x = %f \n",x);  //x = 100.100000
printf("p = %f \n",*p); //p = 100.100000
printf("p = %d \n",*p); //p = 1717986918
printf("y = %f \n",y);  //y = 1717986918.000000
```
La conversión fracasa, ya que **double** utiliza 8 bytes y **int** usa 4, hay una perdida de información.
Entonces vemos que las operaciones de punteros se realizan de acuerdo con sus tipos base en este caso **int**, todas las operaciones deberian ser con **int**.


### PUNTEROS NULL y VOID ###

Un puntero puede "apuntar" o hacer referencia a ningún lado:
```C
int *puntero = NULL
```
O bien, asignandole un cero:
```C
int *puntero = 0
```

También, un puntero puede hacer referencia a cualquier tipo de dato (int, float, double, etc...) gracias a **void**, ejemplo:
```C
int a = 10;
char b = 'x';

void *p = &a;  // void pointer tiene la dirección de 'a', nota que 'a' es un int
p = &b;        // void pointer tiene la dirección de 'b', nota que 'b' es un char
```

Veamos este mismo código en acción:
```C
 int a = 10;
 char b = 'x';
 
 // void pointer tiene la dirección de 'a', nota que 'a' es un int
 void *p = &a; 
    
 printf("p = %p \n",p);    	//Imprimirá su direccin de memoria 
 printf("p = %d \n",*(int *)p); //Usamos *(int *) para convertir a tipo int
 
 // void pointer tiene la dirección de 'b', nota que 'b' es un char
 p = &b; 
 
 printf("p = %p \n",p);		  //Imprimirá su direccin de memoria 
 printf("p = %c \n",*(char *)p);  //Usamos *(char *) para convertir a tipo char
```
La salida del programa es:
```
p = 0x7fff5fbff68c 
p = 10 
p = 0x7fff5fbff68b 
p = x 
```

### COMPARANDO PUNTEROS ###
Suponiendo que tenemos dos punteros **p** y **q**, entonces podemos compararlos simplemente:
```C
if(p < q) {
   // p apunta a menor memoria que q
}
```

### APUNTADOR DE APUNTADORES ###
Un "apuntador de apuntadores", algo escrito como:
```C
int **q; //con dos asteriscos o mas
```
Es simplemente una cadena de apuntadores, recordemos que un puntero contiene la direccion de una variable, entonces, cuando definimos un "apuntador de apuntadores", el primer apuntador contiene la dirección del segundo apuntador, el cuál apunta a la dirección de la variable.

Ejemplo:
```C
int  var = 3000;
int  *p;   //un apuntador simple
int  **q; //un apuntador que apunta a un apuntador, se llama "q"

// asignamos la dirección de "var" a "p"
p = &var;

// asignamos la dirección de "p" usando &, ahora "q" hace referencia a "p"
q = &p;

printf("Valor de var = %d \n", var );
printf("Valor de *p = %d \n", *p );
printf("Valor del apuntador de apuntadores **q = %d \n", **q);
```
La salida es:
```
Valor de var = 3000 
Valor de *p = 3000 
Valor del apuntador de apuntadores **q = 3000 
```

Ahora, intentemos actualizar el valor de **var**. Usaremos el mismo código, pero esta vez escribiremos al final:
```C
 **q = 40; //nuevo valor, tambien funciona si usamos *p = 40;
 printf("Valor de var = %d \n", var);
 printf("Valor de *p = %d \n", *p );
 printf("Valor del apuntador de apuntadores **q = %d \n", **q);
 ```
La salida es:
```
Valor de var = 40 
Valor de *p = 40 
Valor del apuntador de apuntadores **q = 40 
```

### FUNCIONES ###
Hay dos maneras de pasar variables, una es paso por valor y otra es paso por referencia(apuntadores).
En las funciones en C, el paso de valores es por valor, es decir, cuando se pasa un elemento a una función, este elemento copia su valor, a grandes rasgos seria algo así:
* Ejemplo de Paso por Valor:
```C
int var = 10;
funcion(var); //paso por valor
```

* Ejemplo de Paso por Referencia:
```C
int var = 10;
funcion(&var); //paso por referencia, usa &
```

Ejemplos:

* El siguiente código es por "Paso por Valor", es decir, el valor de "b" NO se alterará.
```C
//Declaramos una funcion (arriba de main() ).
void func(int f) {
    f = 12;
}

//Dentro de main()...
//Declaramos una variable y pasamos a "b" como parametro de la funcin
int b = 5;
func(b);
```
Resultado: "b" seguirá valiendo 5.

* El siguiente código es por "Paso por Referencia", es decir, los parámetros actualizarán sus valores. El valor de "b" SI se alterará.
```C
//Declaramos una función, el parámetro sera un puntero
void func(int *p) {
    *p = 12;
}

//Dentro de main()...
int b = 5;
printf("b = %d \n",b); // b = 5

func(&b);  //pasamos la dirección de memoria de b, paso por referencia
printf("b = %d \n",b); //ahora b = 12
```
Resultado: "b" valia 5 y ahora ya vale 12.






