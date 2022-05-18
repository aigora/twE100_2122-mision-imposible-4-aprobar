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
	scanf("%s",j1.apodo);


    fprintf(f2,"%s",j1.apodo);
    fprintf(f2,"%i",j1.puntuacion);
    fclose(f2);

    //bucle menu


	do
    {
        printf("--MENU PRINCIPAL--\n");
        printf("1) Modo dificil.\n2) Modo facil\n3) Salir del programa.\n4) Puntuacion.\n");
        scanf("%i", &eleccionmenu);
        switch(eleccionmenu)
        {
            case 1:
                j1.puntuacion += nivel_dificil();
                printf("enhorabuena conseguiste escapar\n\n\n");
                printf("ahora supera la prueba final\n\n\n");
                j1.puntuacion += trivia_dificil();
                break;
            case 2:
                j1.puntuacion += nivel_facil();
                printf("enhorabuena conseguiste escapar\n\n\n");
                printf("ahora supera la prueba final\n\n\n");
                j1.puntuacion += trivia_facil();
                break;
            case 3:
                break;
            case 4:
                printf("la puntuacion del jugador %s es: %i\n\n",j1.apodo,j1.puntuacion);
            default:
                break;

        }
    }while (eleccionmenu != 3);


	return 0;
}

int nivel_dificil()
{
    int hab= 1;
    int aux;
    int eleccionfacil;
    int puntuacionfacil = 0;

    printf("hola humano, te han traído a ti para que no os extingáis, \n");
    printf("pero eso ya lo sabes, sabrás también que no eres el primero \n");
    printf("que entra por esa puerta,de hecho eres el número 354, así que vete o bueno, muere como los demás \n");
    printf("Bienvenido a la habitacion de la que debes escapar\n");
    printf("A partir de ahora vas a  tener que tener que elegir que prueba quieres elegir para avanzar\n");
    printf("Debes alcanzar una puntuación mínima para llegar a la prueba final (el trivia), que se ira sumando en tu perfil de jugador\n");

    do
    {
        printf("tu puntuacion es %i\n",puntuacionfacil);
        printf("habitacion : %i\n",hab);
        printf("Que prueba deseas realizar?\n");
        printf("1)buscar entre cajas\n2)mirar en una estanteria\n3)encender el ordenador\n");
        scanf(" %i",&eleccionfacil);
        switch(eleccionfacil)
        {
        case 1:
            {
                buscarcajas (&puntuacionfacil, &hab);
                break;
            }
        case 2:
            {
                buscarestanteria (&puntuacionfacil, &hab);
                break;
            }
        case 3:
            {
                juegoaleatorio (&puntuacionfacil, &hab);
                break;
            }
        }
    }
    while(hab < 6);

    return puntuacionfacil;
}
int nivel_facil()
{
    int hab= 1;
    int aux;
    int eleccionfacil;
    int puntuacionfacil = 0;
    printf("Bienvenido a la habitacion de la que debes escapar\n");
    printf("A partir de ahora vas a  tener que tener que elegir que prueba quieres elegir para avanzar\n");
    printf("Debes alcanzar una puntuación mínima para llegar a la prueba final (el trivia), que se ira sumando en tu perfil de jugador\n");

    do
    {
        printf("Tu puntuacion es %i\n",puntuacionfacil);
        printf("habitacion : %i\n",hab);
        printf("Que prueba deseas realizar?\n");
        printf("1)buscar entre cajas\n2)mirar en una estanteria\n3)encender el ordenador\n");
        scanf(" %i",&eleccionfacil);
        switch(eleccionfacil)
        {
        case 1:
            {
                buscarcajas (&puntuacionfacil, &hab);
                break;
            }
        case 2:
            {
                buscarestanteria (&puntuacionfacil, &hab);
                break;
            }
        case 3:
            {
                juegoaleatorio (&puntuacionfacil, &hab);

                break;
            }
        }
    }
    while(hab < 6);


    return puntuacionfacil;
}

void continuar(){
	char enter;
	getchar();
}
