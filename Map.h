#ifndef MAP_H
#define MAP_H


	
typedef struct Map Map;

typedef struct{
  int n;
  char w[60];
}orden;


typedef struct{

  char palabra[1000];
  int cont;
 // char word[10];
  int no_repetidos;

}datos;

typedef struct{

	char nombre_titulo[500];
  unsigned long long  caracteres;
  unsigned long long  palabras;
  datos * cacha;
  
}Libros;

Map * createMap(int (*is_equal)(void* key1, void* key2));

void insertMap(Map * map, void * key, void * value);

void * eraseMap(Map * map, void * key);

void * searchMap(Map * map, void * key);

void * firstMap(Map * map);

void * nextMap(Map * map);

void setSortFunction(Map* map, int (*lower_than)(void* key1, void* key2));

void _pushFront(Map * list, void * key, void * value);

#endif /* MAP_h */