#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void nivel_dificil();
int nivel_facil();


void wordle(int *p_puntuacion);
void ahorcado(int *p_puntuacion);
void tres_en_raya(int *p_puntuacion);
void buscarcajas (int *p_puntuacion);
void buscarestanteria (int *p_puntuacion);

void continuar();
int trivia_facil ();
int trivia_dificil ();



//FUNCIONES DEL AHORCADO
void print_cadena(char cadena[]);  //imprime una cadena
void imprimir_vidas(int vidas);  //imprime los corazones de las vidas

//FUNCIONES DEL TRES EN RAYA
void print_tablero(char matriz[3][3]);
int compr_win(char x, char matriz[3][3]); //devuelve un uno si ese char tiene 3 en raya. Si no, devuelve un 0.
void turno_maquina(char *p_matriz);
void turno_jugador(char *p_matriz);
int empate(char *p_matriz);

