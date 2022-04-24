#include <stdio.h>
#include <string.h>

///AQUI EMPIEZA EL JUEGO DEL AHORCADO///
void ahorcado()
{
    int vidas = 10;
    char frase_secreta[] = "paternidad";        //frase o palabra que adivinar
    char jugador[50];     //frase o palabra que va rellenando el jugador
    int eleccion_jug;       //eleccion de letra o frase por parte del jugador
    int numero_letras = 0;      //numero de letras de la frase secreta
    int i = 0;      //para recorrer bucles
    char letra_jug;  //letra que dice el jugador
    int x = 0;      //se utiliza para comprobar si la letra esta o no en la palabra o frase
    char palabra_entera[50];  //si el jugador elige decir palabra entera, se alamcena aqui

    while (frase_secreta[i] != '\0')
    {
        numero_letras++;
        i++;
    }

    for (i = 0; i < numero_letras; i++)
    {
        jugador[i] = '-';                             //relleno de guiones bajos
    }
    do
    {
        print_cadena(jugador);

        printf("Numero de vidas: %i\n", vidas);
        printf("Elija adivinar letra o palabra entera.\n");
        printf("1)letra\n2)Palabra\n");
        scanf("%i", &eleccion_jug);

        switch (eleccion_jug)
        {
        case 1:
            printf("Diga una letra.\n");
            scanf(" %c", &letra_jug);

            i = 0;
            x = 0;
            while (frase_secreta[i] != '\0')
            {
                if (frase_secreta[i] == letra_jug)
                {
                    x++;
                }

                i++;
            }



            if (x == 0)
            {
                printf("La letra %c no esta.\n", letra_jug);
                vidas--;
            }
            else
            {
                i = 0;
                while (frase_secreta[i] != '\0')
                {
                    if (letra_jug == frase_secreta[i])
                    {
                        jugador[i] = frase_secreta[i];
                    }
                        i++;
                }


            }
            break;
        case 2:
            printf("Escriba la palabra:\n");
            scanf(" %39[^\n]",palabra_entera);
            break;
        }

        printf("\n\n");

        if (strcmp(palabra_entera, frase_secreta) == 0)
            break;


    } while (vidas && strcmp(frase_secreta, jugador));


    if (vidas == 0)
    {
        printf("--GAME OVER--");
    }                                        //resultado final del ahorcado
    else
    {
        printf("Enhorabuena, la palabra era ");
        print_cadena(frase_secreta);
        printf("Has superado la prueba.\n\n");
    }
}





void print_cadena(char cadena[])
{
    int i = 0;
    while (cadena[i] != '\0')
    {
        printf("%c", cadena[i]);
        i++;
    }
    printf("\n");
}



