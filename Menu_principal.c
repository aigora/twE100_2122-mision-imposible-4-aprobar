#include <stdio.h>
#include <locale.h>
void continuar();
int main(){
	setlocale (LC_CTYPE,"spanish");
	int niveldif;
	char apodo[10];
	char aux;
	FILE *f1;
	FILE *f2;
	f1 = fopen("normascaperoom.txt","r");
	f2 = fopen("nombreypuntuaciones.txt","w");
	do{
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



	printf("\nAhora, seleccione la dificultad en la que quieres jugar:\n");
	printf("1) Facil\n2) Dificil\n");
	scanf("%d",&niveldif);
	switch (niveldif){
		case 1:
			printf("\nHas seleccionado nivel fácil\n");
			continuar();
			
			
		break;
		case 2:
			printf("\nHas seleccionado nivel dificil\n");
			continuar();
			
		break;

	}

	}while (niveldif!=1 && niveldif!=2);
	return 0;
}

void continuar(){
	char enter;
	getchar();
}
