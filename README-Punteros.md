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

	- **Int** define el tipo de variable a la que el puntero puede apuntar, en este caso solo podremos apuntar a variables de tipo **Int**. El compilador asume que cualquier direccion que contenga apunta a un entero **Int**.

	- Aunque técnicamente no es obligatorio, en realidad **podriamos apuntar** a un tipo **Float** o **Char** (o cualquier otro), pero esto puede ocasionar errores, entonces debe hacerse con cuidado.


### OPERADORES ###

Los punteros utilizan dos operadores, estos son **&** y * .
* El operador **&** devuelve la dirección de memoria.
* El operador  *  devuelve el valor de alguna variable que ya contiene una dirección de memoria.

Ejemplo:
```C
int variable = 15;
int *direccion = &variable; //un puntero guarda una direccion de memoria, con '&' extraemos la direccion de 'variable'
int valor = *direccion;     //el * sirve para leer el valor de 'direccion', este será 10
   
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


### ARITMETICA DE PUNTEROS ###

