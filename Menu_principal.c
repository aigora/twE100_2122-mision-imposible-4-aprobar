#include <stdio.h>
#include <locale.h>
#include "juegos.h"

void continuar();
void nivel_dificil();
void nivel_facil();

int main(){
	setlocale (LC_CTYPE,"spanish");
	int niveldif;
	char apodo[10];
	char aux;
	int eleccion;
	FILE *f1;
	FILE *f2;
	f1 = fopen("normascaperoom.txt","r");
	f2 = fopen("nombreypuntuaciones.txt","w");

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
	if(f1 == NULL)
    {
        printf("No se pudo abrir el fichero\n");
        exit(1);
    }
    fgets(apodo,10,stdin);
    fprintf(f2,"%s",apodo);
    fclose(f2);


	do
    {
        printf("--MENU PRINCIPAL--\n");
        printf("1) Modo dificil.\n2) Modo facil\n3)Salir del programa.\n");
        scanf("%i", &eleccion);
        switch(eleccion)
        {
            case 1:
                nivel_dificil();
                break;
            case 2:
                nivel_facil();
                break;
            case 3:
                break;
            default:
                break;

        }
    }while (eleccion != 3);


	return 0;
}

void nivel_dificil()
{
    printf("Ha elegido el modo dificil.\n");
}
void nivel_facil()
{
    printf("Ha elegido modo facil.\n");
}

void continuar(){
	char enter;
	getchar();
}
