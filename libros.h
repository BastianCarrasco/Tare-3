#ifndef Libros_h
#define Libros_h
#include "Map.h"

int is_equal_int(void * key1, void * key2);

int lower_than_int(void * key1, void * key2);

int is_equal_string(void * key1, void * key2);

int lower_than_string(void * key1, void * key2);
/*
Producto* crearProducto(char* nombre, char *marca, char * tipo, int stock, int precio);

void agregarProducto(Map* producto_nombre,Map* producto_marca,Map* producto_tipo,Map* producto_stock,Map* producto_precio);

void agregarCarrito(Map * producto_nombre, int cantidad, Map * carrito);
*/
#endif /* Productos_h */