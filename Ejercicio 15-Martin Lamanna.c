#include <stdio.h>



void main (){
char nombre[50];
int nota[3][5], materia[5] = {0};
float promedios[5] = {0}, promedioGeneral;




printf("Ingrese el nombre y apellido del alumno: ");
fflush(stdin);
gets(nombre);

    for (int filas=0; filas<3; filas++){
         for (int columnas=0; columnas<5; columnas++){
             printf("[%d][%d]: ", filas,columnas);
             scanf("%d", &nota[filas][columnas]);
             materia[columnas] += nota[filas][columnas];
             promedioGeneral += nota[filas][columnas];
         }
    }

    printf("Alumno: %s \n", nombre);
    printf("\tMates\tLengua\tIngles\tGeo\tBio\n");



    for ( int filas=0; filas<3; filas++){
            printf("trim%d", filas+1);
         for (int columnas=0; columnas<5; columnas++){
             printf("\t%d ", nota[filas] [columnas]);
         }
         printf("\n");
     }



    for (int i=0; i<5; i++){
         printf("Nota de la materia %d: %d\n", i,materia[i]);
         }



    for (int i=0; i<5; i++){
         promedios[i] = materia[i]/3;
         printf("Promedio de la materia %d: %.2f\n", i,promedios[i]);
         }


    promedioGeneral = promedioGeneral/15;
     printf("El promedio general de las materias es de %.2f", promedioGeneral);



}

