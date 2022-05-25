#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>






///AQUI EMPIEZA EL JUEGO DEL AHORCADO///
void ahorcado(int *p_puntuacion, int *p_hab)
{
    int vidas = 10;
    char frase_secreta[100];        //frase o palabra que adivinar
    char jugador[50];     //frase o palabra que va rellenando el jugador
    int eleccion_jug;       //eleccion de letra o frase por parte del jugador
    int numero_letras = 0;      //numero de letras de la frase secreta
    int i = 0;      //para recorrer bucles
    char letra_jug;  //letra que dice el jugador
    int x = 0;      //se utiliza para comprobar si la letra esta o no en la palabra o frase
    char palabra_entera[50];  //si el jugador elige decir palabra entera, se almacena aqui

    int n_lineas = 0, random;   //para contar las lineas del fichero de palabras
    char c, prueba[100]; //variable auxiliar


    FILE *p_f;
    p_f = fopen("palabras_ahorcado.txt", "r");

    while (fscanf(p_f, "%c", &c) != EOF)
    {
        if (c =='\n')
            n_lineas++;
    }
    fseek(p_f, 0, SEEK_SET);
    random = rand() % n_lineas;
    printf("\nnumero de lineas:%i\n", n_lineas);


i = 0;
    while (fscanf(p_f, "%[^;];\n", frase_secreta) != EOF)
    {
        if (i == random)
        {
            break;
        }
        i++;
    }



    i = 0;
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
        printf("Numero de vidas:");
        imprimir_vidas(vidas);
        printf("Elija adivinar letra o palabra entera.\n");
        printf("1)Letra\n2)Palabra\n");
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
            if (strcmp(palabra_entera, frase_secreta) != 0)
            {
                vidas--;
                printf("Esa no era la palabra.\n");
            }


            break;
        }

        printf("\n\n");

        if (strcmp(palabra_entera, frase_secreta) == 0)
            break;


    } while (vidas && strcmp(frase_secreta, jugador));


    if (vidas == 0)
    {
        printf("--GAME OVER--");
        *p_puntuacion -= 5;
    }                                        //resultado final del ahorcado
    else
    {
        printf("Enhorabuena, la palabra era ");
        print_cadena(frase_secreta);
        printf("Has superado la prueba.\n\n");
        *p_puntuacion += 10;
        *p_hab += 1;
    }
}


void imprimir_vidas(int vidas)
{
    int i;
    printf("(%i) ", vidas);
    for (i = 0; i < vidas; i++)
    {
        printf("%c ", 3);
    }
    printf("\n");
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

                          //TRIVIA//


int trivia_facil ()
{
    int a,b,c,d;

    printf("Bienvenido a la prueba final\n\n");
    printf("Vas a tener que responder a varias preguntas para poder escapar finalmente\n\n");
    printf("De 4 temas: Historia, Geografia, Arte y Cultura general\n\n");



    printf("Primera pregunta: ¿Como se llamaba el monje polaco que fue la primera persona en afirmar que la tierra se movia?\n");
    printf("Opciones:\n 1)Nicolas Copernico\n 2)Galileo\n 3)Schrodinger\n\n");
    scanf("%i",&a);
    printf("Segunda pregunta: ¿Como se llama el tradicional caldo japones hecho con soja fermentada?\n");
    printf("Opciones:\n 1)Ramen\n 2)Sopa de soja\n 3)Miso\n\n");
    scanf("%i",&b);
    printf("Tercera pregunta: ¿Que antigua losa egipcia, que muestra tres tipos de escritura, ha sido clave para descifrar los jeroglificos?\n");
    printf("Opciones:\n 1)Tabula rasa\n 2)Piedra rosetta\n 3)Piedra filosofal\n\n");
    scanf("%i",&c);
    printf("Cuarta pregunta: ¿Que instrumento, utilizado normalmente para conducir el ganado, es capaz de romper la barrera del sonido?\n");
    printf("Opciones:\n 1)Vara\n 2)Pastor electrico\n 3)Latigo\n\n");
    scanf("%i",&d);


    if(a==1&&b==3&&c==2&&d==3)
    {
        printf("Enhorabuena, has acertado todas las preguntas\n\n Escapaste de la habitacion\n\n puedes ver tus resultados antes de salir\n\n");
        return 4;

        //fuera de esta funcion poner la opcion de ver el fichero puntuaciones

    }
    else printf("Error, no conseguiste salir de la habitacion y has muerto de inanicion, vuelvalo a intentar\n");

    return 0;

}
int trivia_dificil ()
{
    int a,b,c,d;

    printf("Bienvenido a la prueba final\n\n");
    printf("Vas a tener que responder a varias preguntas para poder escapar finalmente\n\n");
    printf("De 4 temas: Historia, Geografia, Arte y Cultura general(Presione enter para continuar)\n\n");

    continuar();

    printf("Primera pregunta: ¿Que instrumento invento a mediados del sigo XX frank nakamara tras no llevar suficiente dinero para pagar una cena?\n");
    printf("Opciones:\n 1)Tarjeta de credito\n 2)Cartera\n 3)Los billetes\n\n");
    scanf("%i",&a);
    printf("Segunda pregunta: ¿Cuantos paises sin litoral hay en sudamerica?\n");
    printf("Opciones:\n 1)Uno\n 2)Tres\n 3)Dos\n\n");
    scanf("%i",&b);
    printf("Tercera pregunta: ¿Que querido actor fallecido en el 2014 por suicidio bromeaba diciendo, nunca pelees con alguien feo, no tiene nada que perder?\n");
    printf("Opciones:\n 1)Elton john\n 2)Robin williams\n 3)Conrad winter\n\n");
    scanf("%i",&c);
    printf("Cuarta pregunta: ¿En que mes se observan las perseidas?\n");
    printf("Opciones:\n 1)Enero\n 2)Octubre\n 3)Agosto\n\n");
    scanf("%i",&d);


    if(a==1&&b==3&&c==2&&d==3)
    {
        printf("Enhorabuena, has acertado todas las preguntas\n\n Escapaste de la habitacion\n\n puedes ver tus resultados antes de salir\n\n");
        return 4;

        //fuera de esta funcion poner la opcion de ver el fichero puntuaciones

    }
    else printf("Error, no conseguiste salir de la habitacion y has muerto de inanicion, vuelvalo a intentar\n");
    return 0;
}




				                                  /// Puebas de buscar///


void buscarcajas (int *p_puntuacion, int *p_hab)
{
    int n, a;

    n = rand() % 50 + 1;

 if (n<=10)
  {
    printf ("la llave esta en las cajas\n");
    printf ("¿Quieres cogerla?\n");
    printf ("Y/N\n");
    scanf (" %c", &a);

    if (a==89 || a==121)
            {

        printf ("has conseguido la llave\n");
        *p_puntuacion += 3;
        *p_hab += 1;
            };
  } else printf ("no hay nada en las cajas\n");


}


void buscarestanteria (int *p_puntuacion, int *p_hab)
{
    int n, a, b;


    n = rand() % 10 + 1;

 if (n<=5)
 {
    printf ("la llave esta en la estanteria\n");
    printf ("¿Quieres cogerla?\n");
    printf ("Y/N\n");
    scanf (" %c", &a);
    if (a==89 || a==121)
      {


            b = rand() % 10 + 1;
            if (b>=5)
            {
                printf ("Te has caido de la estanteria\n");
                *p_puntuacion -= 3;
            }  else {
                printf ("has conseguido la llave\n");
                *p_puntuacion += 3;
                *p_hab += 1;}
      }

 } else printf ("no hay nada en la estanteria\n");

}



                                                    ///TRES EN RAYA///


int compr_win(char x, char matriz[3][3])
{
        int i; //para recorrer bucles
        for (i = 0; i < 3; i++)
        {
            if (matriz[i][0] == x && matriz[i][1] == x && matriz[i][2] == x)
                return 1;
        }
        for (i = 0; i < 3; i++)
        {
            if (matriz[0][i] == x && matriz[1][i] == x && matriz[2][i] == x)
                return 1;
        }
        if (matriz[0][0] == x && matriz[1][1] == x && matriz[2][2] == x)
            return 1;
        if (matriz[0][2] == x && matriz[1][1] == x && matriz[2][0] == x)
            return 1;

        return 0;

}

void turno_jugador(char *p_matriz, char eleccion)
{
        int i;
        for (i = 0; i < 9; i++)
        {
            if (p_matriz[i] == eleccion)
                p_matriz[i] = 'x';
        }
}

void tres_en_raya(int *p_puntuacion, int *p_hab)
{
    char matriz_tablero[3][3] = {'1', '2', '3',
                                '4', '5', '6',
                                '7', '8', '9'};
    char eleccion__jugador, *p;
    p = matriz_tablero;
    do
    {
            turno_maquina(p);
            if (empate(p) == 1)
            {
                printf("Ha habido empate.\n");
                break;
            }
            printf("\n");
            print_tablero(p);
            printf("\n");
            if (compr_win('o', matriz_tablero) == 1)
            {
                printf("Has perdido.\n");
                *p_puntuacion -= 5;
                 break;
            }
            scanf(" %c", &eleccion__jugador);
            turno_jugador(p, eleccion__jugador);
            if (empate(p) == 1)
            {
                print_tablero(p);
                printf("\n");
                printf("Ha habido empate.\n");
                break;
            }

    } while (compr_win('x', matriz_tablero) != 1 && compr_win('o', matriz_tablero) != 1);

    if (compr_win('x', matriz_tablero) == 1)
    {
        print_tablero(p);
        printf("\n--TRES EN RAYA--, ENHORABUENA\n");
        *p_puntuacion += 10;
        *p_hab += 1;
    }
}
//funciones del tres en raya//


void print_tablero(char matriz[3][3])
{
    printf("  %c  |  %c  |  %c  \n", matriz[0][0], matriz[0][1], matriz[0][2]);
    printf("-----------------\n");
    printf("  %c  |  %c  |  %c  \n", matriz[1][0], matriz[1][1], matriz[1][2]);
    printf("-----------------\n");
    printf("  %c  |  %c  |  %c  \n", matriz[2][0], matriz[2][1], matriz[2][2]);
}

void turno_maquina(char *p_matriz)
{
    int n;//numero random que da una posicion de la matriz
    do
    {
        n = rand() % 9;

        if (p_matriz[n] != 'x' && p_matriz[n] != 'o')
        {
            p_matriz[n] = 'o';
            break;
        }
    } while (1);


}

int empate(char *p_matriz)
{
    int i, contador = 0;
    for (i = 0; i < 9; i++)
    {
        if (p_matriz[i] == 'o' || p_matriz[i] == 'x')
        {
            contador++;
        }
    }
    if (contador == 9 && compr_win('x', p_matriz) != 1 && compr_win('o', p_matriz) != 1)
    {
        return 1;
    } else
    {
        return 0;
    }


}
///FIN DEL TRES EN RAYA///

/// juego aleatorio ///

void juegoaleatorio (int *p_puntuacion, int *p_hab){
int n = rand () % 3 + 1;
switch (n)
    {
    case 1:
        ahorcado(p_puntuacion,p_hab);
        break;
    case 2:
        ahorcado (p_puntuacion,p_hab);
        break;
    case 3:
        tres_en_raya (p_puntuacion,p_hab);
        break;
    default:
        break;
    }


}




