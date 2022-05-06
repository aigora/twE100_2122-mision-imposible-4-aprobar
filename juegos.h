#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void nivel_dificil();
int nivel_facil();


void wordle(int *p_puntuacion);
void ahorcado(int *p_puntuacion);
void tres_en_raya(int *p_puntuacion);
void continuar();
int trivia_facil ();
int trivia_dificil ();
void buscarcajas (int *p_puntuacion);
void buscarestanteria (int *p_puntuacion);


//FUNCIONES DEL AHORCADO

void print_cadena(char cadena[]);  //imprime una cadena
void imprimir_vidas(int vidas); //imprime los corazones de las vidas

