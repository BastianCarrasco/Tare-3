#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Map.h"
#include "libros.h"
#include <ctype.h>
#include <math.h>



int compare(const void *_a, const void *_b) {
 
        int *a, *b;
        
        a = (int *) _a;
        b = (int *) _b;
        
        return (*b-*a);
}


void contexto(char * texto, char * palabra){
  
  char linea[1024];
  FILE * libro = fopen(texto,"r");

  while (fgets(linea , 1024 , libro )!= NULL){

    if (strstr(linea , palabra )!= NULL){
      printf("------------------------------------\n");
      printf("%s\n",linea);
      printf("------------------------------------\n");
    }
  }
}

void encuentra_palabras(char * texto, char * palabra){

  unsigned long long contador=0;
  char linea[1024];
  
  FILE * libro = fopen(texto,"r");

// se lee la linea hasta que llege un salto de linea
// o se alacanze el maximo de longitud. y lo guarda en el mapa libro

  while (fgets(linea , 1024 , libro )!= NULL){

// se usa la funcion strstr para que analize la linea
// y despues me devuelva la palabra

    if (strstr(linea , palabra )!= NULL){
      contador++;
    }
  }

  if (contador>0){
    printf("Titulo: %s\n",texto);
    printf("Repeticiones: %llu\n",contador);
  }

}

unsigned long long contar_c(char * texto){
  
  unsigned long long contador=0;
  char caracter;

 
 FILE * lista = fopen(texto,"r");


// FILE * lista = fopen ('Libros/texto', "r");
// myFile = open('myFolder/filename.txt', 'r')

  while(1){

    caracter=fgetc(lista);
    if (caracter==EOF) break;
    if (caracter!=32 && caracter!=10 )
    contador++;
  }
  return contador;
}

unsigned long long contar_palabras(char * texto, Libros * n){
  unsigned long long p=0;
  char palabra[100];

  FILE * lista = fopen(texto,"r");

  while(!feof(lista)){

    fscanf(lista,"%s",palabra);
 //   printf("%s\n",palabra);
    p++;
      
    }

    return p;
}

int main(){

// MAPA CON CLAVE LIBRO//
Map* libro = createMap(is_equal_string);
setSortFunction(libro, lower_than_string);

 // MAPA CON CLAVE CARACTERES //
Map* libro_caracteres = createMap(is_equal_string);
setSortFunction(libro_caracteres, lower_than_string);

// MAPA CON CLAVE PALABRAS //
Map* libro_palabras = createMap(is_equal_string);
setSortFunction(libro_palabras, lower_than_string);

// MAPA CON CLAVE TIPO //
Map* datos_palabras = createMap(is_equal_string);
setSortFunction(datos_palabras, lower_than_string);

Map* contar = createMap(is_equal_string);
setSortFunction(contar, lower_than_string);

/*
// MAPA INT CON CLAVE STOCK //
Map * producto_stock = createMap(is_equal_int);

// MAPA INT CON CLAVE STOCK //
Map * producto_precio = createMap(is_equal_int);
    
      

//p = crearProducto("Coca Cola 1 lt", "coca-cola", "bebida", 200, 1000);
      
  //    insertMap(producto_nombre, p->nombre, p);
    //  insertMap(producto_marca, p->marca, p);
      //insertMap(producto_tipo, p->tipo, p);
      //insertMap(producto_stock, &p->stock, p);
      //insertMap(producto_precio, &p->precio, p);

*/
//--------------------------------------------------------
 


//------------------------------------------------------
      
int op=10;

    while (op!=0) 
    {   
    printf("\n");
    printf("--------------------------------------------\n");  
		printf("|        ✔  Bienvenido al Menú ✔           |\n");
    printf("--------------------------------------------\n");
		printf("| 1. Cargar documentos                      |\n");
		printf("| 2. Mostrar documentos ordenados           |\n");
		printf("| 3. Buscar por palabra                     |\n");
		printf("| 4. Palabras con mayor frecuencia         |\n");
		printf("| 5. Palabras más relevantes            x   |\n");
		printf("| 6. Buscar palabra en documento            |\n");
    printf("| 0. Salir                                  |\n");
    printf("--------------------------------------------\n");

    printf("| ⏬ Indica la opción ⏬ |\n");
    printf("--------------------------\n");
		printf("👉 "); scanf("%d", &op);
    printf("\n");

    char *token;
    Libros *b=NULL;;
    char titulos[500];
    char buscar_palabra[300];
    char buscar_titulo[300];
    char buscar[300];
    char linea[300];
   
    /////////////////////////
    char guarda_palabra[200];
    char clon[200];
    char cambio[10];
   
   datos * c = NULL;
   
  

    
		
		switch (op) 
    {

//➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖//

      case 1:

      printf("Ingrese titulos.txt\n");
     
      scanf(" %[^\n]",titulos);
      strcat(titulos," _F");

      int primero = 0; 
      while(1){

      Libros *vector = malloc(sizeof(Libros));
      

      if (primero==0){

        token = strtok(titulos," ");
        strcpy(vector->nombre_titulo,token);
        primero++;

      }else{
        token = strtok(NULL," ");
        strcpy(vector->nombre_titulo,token);
        
      }
      
      if (strcmp(token,"_F")==0) break;


      vector->caracteres = contar_c(token);
      vector->palabras=contar_palabras(token,vector) ;

      insertMap(libro,vector->nombre_titulo,vector);
      insertMap(libro_caracteres,&vector->caracteres,vector);
      insertMap(libro_palabras,&vector->palabras,vector);
    }
    break;
  

//➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖//
      case 2:

      b=firstMap(libro);

       while (b!=NULL){

        printf("Nombre: %s\n",b->nombre_titulo);
        printf("Caracteres: %llu\n",b->caracteres);
        printf("Palabras: %llu\n",b->palabras);

        b=nextMap(libro);
        printf("\n");
      }
      break;

    
//➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖//   
    case 3:

    
    printf("Ingrese palabra a buscar\n");
    scanf("%s",buscar_palabra);
    printf("------------------------------------\n");

    b=firstMap(libro);

    while (b!=NULL){

      encuentra_palabras(b->nombre_titulo, buscar_palabra);
      b = nextMap(libro);
      printf("\n");
    }


    break;

//➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖//
    case 4:

    printf("Ingrese nombre texto\n");

    char titulo_busca[50];

    scanf(" %[^\n]", titulo_busca);

    printf("Un momento por favor\n");

    FILE * lista = fopen(titulo_busca,"r");
     
          while(!feof(lista)){
            char * x;
            int i;

              fscanf(lista, "%s",guarda_palabra);

              datos * vector2 = malloc(sizeof(datos));

              for(i = 0; guarda_palabra[i]; i++){
                guarda_palabra[i] = tolower(guarda_palabra[i]);
                }

              if ((guarda_palabra[strlen(guarda_palabra)-1]<97 || guarda_palabra[strlen(guarda_palabra)-1]>123)){

                strncpy(clon,guarda_palabra,strlen(guarda_palabra)-1);
                strcpy(guarda_palabra,clon);
                strcpy(clon," ");
              }  

              if (searchMap(datos_palabras, guarda_palabra) == NULL && strstr(guarda_palabra,"*")==0 && strstr(guarda_palabra,"-")==0 && strstr(guarda_palabra,".")==0 && strstr(guarda_palabra,"1")==0 && strstr(guarda_palabra,"2")==0 && strstr(guarda_palabra,"3")==0 && strstr(guarda_palabra,"4")==0 && strstr(guarda_palabra,"5")==0 && strstr(guarda_palabra,"6")==0 && strstr(guarda_palabra,"7")==0 && strstr(guarda_palabra,"8")==0 && strstr(guarda_palabra,"9")==0 && strstr(guarda_palabra,"0")==0 && strstr(guarda_palabra,"/")==0 && strstr(guarda_palabra,"#")==0 && strstr(guarda_palabra,"+")==0 && strstr(guarda_palabra,";")==0 && strstr(guarda_palabra,":")==0 && strstr(guarda_palabra,"_")==0 && strstr(guarda_palabra,"@")==0)  {
                strcpy(vector2->palabra,guarda_palabra);
                vector2->cont=1;
                insertMap(datos_palabras,vector2->palabra,vector2);
              }
               
               else{

               c = firstMap(datos_palabras);

               while(c!=NULL){

                 if (strcmp(guarda_palabra,c->palabra)==0){
                   c->cont++;
                   break;
                 }
                 c = nextMap(datos_palabras);
               }  
                
              }
            }
         

     c = firstMap(datos_palabras);

    while(c!=NULL){
      sprintf(cambio, "%d", c->cont);
      strcpy(c->word,cambio);

      insertMap(contar,c->word,c);
      c = nextMap(datos_palabras);
    }

    c = firstMap(datos_palabras);

    int numero_de_repetidos=0;
    orden *arreglo=calloc(100000, sizeof(orden));
    int indice=0;

    while(c!=NULL){
      arreglo[indice].n=c->cont;
      strcpy(arreglo[indice].w,c->palabra);
      indice++;
      c = nextMap(datos_palabras);
    }
    
    qsort(arreglo, indice, sizeof(orden), &compare);

    indice = 0;
    while(indice<11){

    printf("%d ",arreglo[indice].n);
    printf("%s\n ",arreglo[indice].w);
    indice++;
    }

    













    
    break;

//➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖//   
    case 6:

    printf("Ingrese titulo donde buscar\n");
    scanf("%s",buscar_titulo);

    printf("Ingrese palabra a buscar\n");
    scanf("%s",buscar_palabra);

    b=firstMap(libro);

    while (b!=NULL){

      if (strcmp(b->nombre_titulo,buscar_titulo)==0){

      contexto(b->nombre_titulo, buscar_palabra);
      
      printf("\n");
      
      break;

      }
      b = nextMap(libro);
      
    }
}

}
}

