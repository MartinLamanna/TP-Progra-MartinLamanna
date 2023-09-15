#include <stdio.h>
#include <string.h>     /**        para usar fn de string       **/
#include <stdlib.h>     /**       para usar memoria dinamica     **/
#include <stdbool.h>    /**            para usar bool           **/
#include <math.h>       /** para cuentas matematicas avanzadas  **/
#include <time.h>       /**       para generararNumAleatorio    **/
#include <conio.h>      /**             ¿para juegos?            **/


#define SEMILLA_RANDOM() srand(time(NULL))
#define TAM_ARRAY( arr ) (sizeof(arr)/sizeof(arr[0]))
#define EN_RANGO(a, x, b) ( (x)>=(a) && (x)<=(b) )
#define LIMPIAR() system("cls")
#define PAUSA() system("pause")
#define PAUSAR() getch()



void agregarEntero(int arrResta[], int num) {
    int posicion = 0;
    while (arrResta[posicion] != 0) {
        posicion++;
    }
    arrResta[posicion] = num;
    posicion++;

}
void unirArrays(int arrResta[], int vec[], int tam) {
    int posicion = 0;



    // Encuentra la posición en arrResta donde debemos comenzar a agregar elementos de vec
    while (arrResta[posicion] != 0) {
        posicion++;
    }



    // Agregar los elementos de vec al final de arrResta
    for (int i = 0; i < tam; i++) {
        arrResta[posicion] = vec[i];
        posicion++;
    }
}
bool arrayIgualEntero(int vector[], int tamano, int elemento) {
    bool flag = false;
    for (int i = 0; i < tamano; i++) {
        if (vector[i] == elemento) {
            flag =  true; // El elemento ya existe en el vector
        }
    }
    return flag; // El elemento no existe en el vector
}
int generarNumAleatoreo(int valorMin, int valorMax){
    /*srand(time(NULL));*/
    return (valorMin + ( rand() % (valorMax - valorMin + 1)));
}



// Ejercicio:



void inicArray(int arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        arr[i] = generarNumAleatoreo( 20, 35);
    }
}



int mostrarMenu(void){
    int opc;
    do{
        printf("\n-------- MENU --------\n");
        printf("  |1| Mostrar los vectores y cuantos valores se repiten en cada vector. \n");
        printf("  |2| Mostrar los vectores sin que se repitan los datos.\n");
        printf("  |3| Mostrar la union entre ambos vectores.\n");
        printf("  |4| Mostrar la interseccion entre ambos vectores.\n");
        printf("  |5| Mostrar la resta entre ambos vectores (A-B).\n");
        printf("  |6| Mostrar la resta del segundo vector menos el primer vector (B-A).\n");
        printf("  |7| salir.\n");
        printf("\nIngrese la opcion que prefiera: ");
        scanf("%d", &opc);
    }while( !EN_RANGO( 1, opc, 7) );



    return opc;
}



void mostrarArray(int arr[], int tam){
    for (int i = 0; i < tam; i++) {
        printf("[%2.d] - %d\n", (i+1), arr[i]);
    }
}



void copiarArray(int arrCopy[], const int arr[], int tam){
    for (int i = 0; i < tam; i++) {
        arrCopy[i] = arr[i];
    }
}



void mostrarRepetidos(const int arr[], int tam){
    int arrCopy[tam];
    copiarArray( arrCopy, arr, tam);
    for (int i = 0; i < tam; i++) {
        if (arrCopy[i] != -1) {
            int contador = 1;
            for (int j = i + 1; j < tam; j++) {
                if (arrCopy[j] == arrCopy[i]) {
                    contador++;
                    arrCopy[j] = -1;
                }
            }
            if( contador > 1 ){
                printf("\n%d (Aparece %d veces)", arrCopy[i], contador);
            }
        }
    }
}



void mostrarNoRepetidos(const int arr[], int tam){
    int arrCopy[tam];
    copiarArray( arrCopy, arr, tam);
    for (int i = 0; i < tam; i++) {
        if (arrCopy[i] != -1) {
            int contador = 1;
            for (int j = i + 1; j < tam; j++) {
                if (arrCopy[j] == arrCopy[i]) {
                    contador++;
                    arrCopy[j] = -1; // Marca el elemento como contado
                }
            }
            if( contador < 2 ){
                printf("\n%d", arrCopy[i]);
            }
        }
    }
}



void mostrarInterseccion(const int arr1[], const int arr2[], int tam){
    for (int i = 0; i < tam; i++){
        for (int j = 0 ; j < tam; j++){
            if ( arr1[i] == arr2[j] ){
                printf("%d - ", arr1[i]);
            }
        }
    }
}



void mostrarUnion(const int arr1[], const int arr2[], int tam){
    int tamanoUnion=0;
    int vectorUnion [20] = {0};



    for (int i = 0; i < tam; i++) {
        if ( !arrayIgualEntero(vectorUnion, tamanoUnion, arr1[i]) ) {
            vectorUnion[tamanoUnion] = arr1[i];
            tamanoUnion++;
        }
    }
    for (int i = 0; i < tam; i++) {
        if ( !arrayIgualEntero(vectorUnion, tamanoUnion, arr2[i]) ) {
            vectorUnion[tamanoUnion] = arr2[i];
            tamanoUnion++;
        }
    }



    mostrarArray( vectorUnion, tamanoUnion);
}



void eliminarRepetidos(int arrPuro[],const int arrRepe[], int tam){
    int cont;
    for (int i = 0; i < tam; i++) {
        cont = 0;
        for (int j = 0; j < tam; j++){
            if( arrRepe[i] == arrRepe[j] ){
                cont++;
            }
        }
        if(cont == 1){
            agregarEntero( arrPuro, arrRepe[i]);
        }
    }
}



void mostrarRestaArrays(const int arr1[], const int arr2[], int tam){
    int vector1 [10] = {0};
    int vector2 [10] = {0};
    int vectorResta[20] = {0};
    int vector[20] = {0};



    eliminarRepetidos( vector1, arr1, 10);
    eliminarRepetidos( vector2, arr2, 10);



    unirArrays( vector, vector1, 10);
    unirArrays( vector, vector2, 10);

    eliminarRepetidos( vectorResta, vector, 20);
    mostrarArray( vectorResta, 20);
}





void main(void) {
    int opcion;
    int arr1[10] = {0}, arr2[10] = {0};
    SEMILLA_RANDOM();
    inicArray(arr1, TAM_ARRAY(arr1));
    inicArray(arr2, TAM_ARRAY(arr2));



    do{
        LIMPIAR();

        opcion = mostrarMenu();

        if(opcion != 7){
            printf("\n-------- VECTOR 1 --------\n");
            mostrarArray( arr1, TAM_ARRAY(arr1));
            printf("\n-------- VECTOR 2 --------\n");
            mostrarArray( arr2, TAM_ARRAY(arr2));
        }

        switch (opcion) {
            case 1:
                printf("\n-------- NUM REPETIDOS VECTOR 1 --------");
                mostrarRepetidos( arr1, TAM_ARRAY(arr1));
                printf("\n\n-------- NUM REPETIDOS VECTOR 2 --------");
                mostrarRepetidos( arr2, TAM_ARRAY(arr2));
            break;
            case 2:
                printf("\n\n-------- NUM NO REPETIDOS VECTOR 1 --------\n");
                mostrarNoRepetidos( arr1, TAM_ARRAY(arr1));
                printf("\n\n-------- NUM NO REPETIDOS VECTOR 2 --------\n");
                mostrarNoRepetidos( arr2, TAM_ARRAY(arr2));
            break;
            case 3:
                printf("\n\n-------- UNION ENTRE EL VECTOR 1 Y EL VECTOR 2 --------\n\n");
                mostrarUnion( arr1, arr2, TAM_ARRAY(arr2)); // ver que onda
            break;
            case 4:
                printf("\n\n-------- INTERSECCION ENTRE EL VECTOR 1 Y EL VECTOR 2 --------\n\n");
                mostrarInterseccion( arr1, arr2, TAM_ARRAY(arr2)); // ver que onda
            break;
            case 5:
                printf("\n\n-------- RESTA ENTRE EL VECTOR 1 Y EL VECTOR 2 --------\n\n");
                mostrarRestaArrays( arr1, arr2, TAM_ARRAY(arr2));
            break;
            case 6:
                printf("\n\n-------- RESTA ENTRE EL VECTOR 2 Y EL VECTOR 1 --------\n\n");
                mostrarRestaArrays( arr2, arr1, TAM_ARRAY(arr2));
            break;
        }

        PAUSA();
    }while( opcion != 7 );



}
