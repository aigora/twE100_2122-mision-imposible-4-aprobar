#include <stdio.h>

void Continuar();
int main(){
	int niveldif;
	char aux;
	FILE *f1;
	FILE *f2;
	f1 = fopen("normascaperoom.txt","r");
	do{
	printf("Bienvenido a nuestro scaperoom (presione enter para continuar)\n");
	Continuar();
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

	Continuar();
	printf("Escriba el numero de jugadores\n");
	//se introducen los datos en el fichero f2
	printf("\nAhora, seleccione la dificultad en la que quieres jugar:\n");
	printf("1) Facil\n2) Dificil\n");
	scanf("%d",&niveldif);
	switch (niveldif){
		case 1:
			printf("\nHas seleccionado nivel facil\n");
		break;
		case 2:
			printf("\nHas seleccionado nivel dificil\n");
		break;

	}

	}while (niveldif!=1 && niveldif!=2);
	return 0;
}

void Continuar(){
	char enter;
	getchar();
}
