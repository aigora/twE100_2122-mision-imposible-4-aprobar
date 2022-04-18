#include <stdio.h>
void Continuar();
int main(){
	int niveldif;
	do{
	printf("Bienvenido a nuestro scaperoom (presione enter para continuar)\n");
	Continuar();
	printf("Para empezar necesitas saber que es un scaperoom (presione enter para continuar)\n");
	//fichero con las normas
	Continuar();
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
