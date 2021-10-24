#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Map.h"
#include"libros.h"


/*
  funciÃ³n para comparar claves de tipo string
  retorna 1 si son iguales
*/
int is_equal_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2)==0) return 1;
    return 0;
}

/*
  funciÃ³n para comparar claves de tipo string
  retorna 1 si son key1<key2
*/
int lower_than_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2) < 0) return 1;
    return 0;
}

/*
  funciÃ³n para comparar claves de tipo int
  retorna 1 si son iguales
*/
int is_equal_int(void * key1, void * key2) {
    if(*(int*)key1 == *(int*)key2) return 1;
    return 0;
}

/*
  funciÃ³n para comparar claves de tipo int
  retorna 1 si son key1<key2
*/
int lower_than_int(void * key1, void * key2) {
    if(*(int*)key1 < *(int*)key2) return 1;
    return 0;
}



/*Producto* crearProducto(char* nombre, char *marca, char * tipo, int stock, int precio) {
  Producto* p = (Producto*) malloc (sizeof(Producto));
	strcpy(p->nombre, nombre);
  strcpy(p->marca, marca);
  strcpy(p->tipo, tipo);
  p->stock = stock;
	p->precio = precio;
  return p;
}*/

/*void agregarProducto(Map* producto_nombre,Map* producto_marca,Map* producto_tipo,Map* producto_stock,Map* producto_precio){

Producto * P = (Producto*) malloc (sizeof(Producto));
	int elementosMapa = 0;
	P = firstMap(producto_nombre);
  while (P!=NULL) 
  {
    elementosMapa++;
  
  }*/

	//se busca si el nombre ya esta en almacenamiento//

	/*char auxNombre[20];
	Producto* aux;
	printf("Ingrese nombre del Producto %c : ",elementosMapa);
	scanf("%s",auxNombre);
	aux = searchMap(producto_nombre, &auxNombre);

	//si está se imprime que no se puede ingresar nuevo producto//

	if (aux != NULL) 
  {
		printf("Este producto ya existe, no lo puedes agregar");
	}
	else
	//si el Nombre no está en almacenamiento, permite que el usuario la ingrese/
	{
		if (elementosMapa <= 100 ) 
    {
			int auxstock, auxprecio;
			char auxmarca[10];
			char auxtipo[50];
			printf("Ingrese Marca del Producto : ");
			scanf("%s",auxmarca);
			printf("Ingrese Tipo de Producto : ");
			scanf("%s",auxtipo);
			printf("Ingrese Stock del Producto : ");
			scanf("%d",&auxstock);
			printf("Ingrese Precio del Producto : ");
			scanf("%d",&auxprecio);

  printf("\n");
  printf("------------------------------------------\n");
      printf("    Producto agregado con éxito.\n");
  printf("------------------------------------------\n");

			Producto *producto_buscado = searchMap(producto_nombre, &auxNombre);
			if (NULL == producto_buscado)	// No esta el ´producto
			{
				Producto* p = crearProducto(auxNombre, auxmarca, auxtipo, auxstock, auxprecio);
				insertMap(producto_nombre, &p->nombre, p);

			}
			else		// Si ya esta
			{
				producto_buscado->stock++;
			}
		}
		else
		{
			printf("No hay espacio suficiente en el stock");
		}
	}	

}
*/
/*void agregarCarrito(Map * producto_nombre, int cantidad, Map * carrito){

  Carrito * c = (Carrito*) malloc (sizeof(Carrito));

  printf("-----------------\n");
  printf("| 🛒 Carrito 🛒 |\n");
  printf("-----------------\n");
  printf("|               |\n");
    c = firstMap(producto_nombre);
    while (c) {
        printf("| %s (%d) |\n", c->nombre, c->cantidad);
        printf("-----------------\n");
        c = nextMap(producto_nombre);
    }
  
}*/