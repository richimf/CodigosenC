# PUNTEROS #

### QUE ES ###
Un puntero es una variable que contiene una dirección de memoria. Así como una variable puede contener un numero *int b = 5*, esta variable contiene una dirección de memoria (son unos numeritos tipo 103043 y siempre cambian).

<br></br>
Ahora, esta dirección de memoria es la ubicación de un objeto (o variable) en la memoria, digamos que en ese lugar vive la variable.
Entonces, si una variable **A** contiene la dirección de otra variable **B**, decimos que **A** apunta **B**. Esta variable **A** sera el puntero y para declarar un puntero lo hacemos así:

> tipo_de_dato *variable;

ejemplo:
```C
	int *puntero;
```

*Importante:

	- *Int* define el tipo de variable a la que el puntero puede apuntar, en este caso solo podremos apuntar a variables de tipo *Int*. El compilador asume que cualquier direccion que contenga apunta a un entero *Int*.

	- Aunque tecnicamente no es obligatorio, en realidad podriamos apuntar a un tipo *Float* o *Char* (o cualquier otro), pero esto puede ocasionar errores, entonces debe hacerse con cuidado. Dicho esto, 


### USOS ###

Los punteros son utilizados en estructuras de datos dinamicas tales como en Aboles binarios (Binary Tree) o listas enlazadas (Linkedlist).
