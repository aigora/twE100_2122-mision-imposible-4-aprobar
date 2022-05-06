#include <stdio.h>
#include "juegos.h"

void continuar();

typedef struct
{
    char apodo[10];
    int puntuacion;

}jugador;


int main(){

    //variables
    srand(time(NULL));
	jugador j1 = {"nombre",0};
	char aux;
	int eleccionmenu;
	FILE *f1;
	FILE *f2;
	f1 = fopen("normascaperoom.txt","r");
	f2 = fopen("nombreypuntuaciones.txt","w");

	//Comienza el programa


	printf("Bienvenido a nuestro scaperoom (presione enter para continuar)\n");
	continuar();

	printf("Para empezar necesitas saber que es un scaperoom (presione enter para continuar)\n");
	if(f1 == NULL)
    {
        printf("No se pudo abrir el fichero\n");
        exit(1);
    }
    while(aux != EOF)
    {
        aux = fgetc(f1);
        printf("%c",aux);
    }
    fclose(f1);

	continuar();


	printf("Escriba el nombre del jugador (maximo 10 letras)\n");
	scanf("%s",&j1.apodo);


    fprintf(f2,"%s",j1.apodo);
    fprintf(f2,"%i",j1.puntuacion);
    fclose(f2);

    //bucle menu


	do
    {
        printf("--MENU PRINCIPAL--\n");
        printf("1) Modo dificil.\n2) Modo facil\n3)Salir del programa.\n");
        scanf("%i", &eleccionmenu);
        switch(eleccionmenu)
        {
            case 1:
                nivel_dificil();
                break;
            case 2:
                nivel_facil();
                j1.puntuacion += nivel_facil();
                break;
            case 3:
                break;
            default:
                break;

        }
    }while (eleccionmenu != 3);


	return 0;
}

void nivel_dificil()
{
    printf("Has cometido un grave error, bienvenido a tu peor pesadilla\n");
    printf("Has decidido realizar las pruebas en modo hardcore\n");
}
int nivel_facil()
{
    int aux;
    int eleccionfacil;
    int puntuacionfacil = 0;
    printf("Bienvenido a la habitacion de la que debes escapar\n");
    printf("A partir de ahora vas a  tener que tener que elegir que prueba quieres elegir para avanzar\n");
    printf("Debes alcanzar una puntuación mínima para llegar a la prueba final (el trivia), que se ira sumando en tu perfil de jugador\n");

    do
    {
        printf("Que prueba deseas realizar?\n");
        printf("1)Caja sorpresa\n2)Ahorcado\n3)buscar en estanteria\n4)wordle\n5)tres en raya\n6)salir\n");
        scanf("%i",&eleccionfacil);
        switch(eleccionfacil)
        {
        case 1:
            {
                buscarcajas (&puntuacionfacil);
                printf("tu puntuacion es %i\n",puntuacionfacil);
                break;
            }
        case 2:
            {
                ahorcado(&puntuacionfacil);
                break;
            }
        case 3:
            {
                buscarestanteria (&puntuacionfacil);
                break;
            }
        case 4:
            {
                break;
            }
        case 5:
            {
                tres_en_raya(&puntuacionfacil);
                break;
            }
        case 6:
            {
                puntuacionfacil = 21;
                break;
            }
        }
    }
    while(puntuacionfacil <= 20);

    return puntuacionfacil;
}

void continuar(){
	char enter;
	getchar();
}
