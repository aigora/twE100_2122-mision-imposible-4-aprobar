#include <stdio.h>
void Continuar();
int main(){
	int niveldif;
	do{
	printf("Bienvenido a nuestro Escaperoom\n");
	Continuar();
	printf("Para empezar necesitas saber qué es un escaperoom\n");
	//fichero con las normas
	Continuar();
	printf("\nAhora, seleccione la dificultad en la que quieres jugar:\n");
	printf("1) Fácil\n2) Difícil\n");
	scanf("%d",&niveldif);
	switch (niveldif){
		case 1:
			printf("\nHas seleccionado nivel fácil\n");
		break;
		case 2:
			printf("\nHas seleccionado nivel difícil\n");
		break;
		
	}
	
	}while (niveldif!=1 && niveldif!=2);
	return 0;
}
	
void Continuar(){
	char enter;
	getchar();
}
