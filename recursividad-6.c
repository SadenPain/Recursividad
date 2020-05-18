/*
 * =====================================================================================
 *
 *       Filename:  recursividad-6.c
 *
 *    Description:  Algoritmo recursivo que determine si en un vector A de n enteros
 *    existen dos parejas consecutivas de elementos tales que las sumas sean identicas.
 *
 *        Version:  1.0
 *        Created:  05/04/2020 02:48:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  SadenPain
 *   Organization:  Universidad de Cadiz
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


/* 
 * ===  FUNCTION  ======================================================================
 *         Precondicion: Recibe los parametros declarados en la funcion llamada
 *         Postcondicion: Calcular si la suma de dos pares consecutivos es igual,
 *         en caso afirmativo devuelve 1, en caso contrario 0.
 * =====================================================================================
 */
int r_func ( int *v, int A_size, int i )
{
  //Como ya ha comprobado todas las parejas y ninguna devuelve 1, devolvemos 0
  if ( (i-3) == A_size )
    return 0;
  // Si se cumple el caso de que existan dos pares consecutivos que su suma sea la misma
  if ( v[i] + v[i+1] == v[i+2] + v[i+3]) 
    return 1; // Devuelve 1, caso afirmativo
  else
    return r_func ( v, A_size, i+1 ); // Si no, sigue comprobando
}		/* -----  end of function r_func  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Precondicion: Recibir el vector y su tamanio
 *         Postcondicion: Llamar a la funcion recursiva 
 * =====================================================================================
 */
int func_call ( int *v, int A_size ) 
{
  int i = 0;
  if ( A_size <= 2 )
    return -1;
  else 
    return r_func ( v, A_size, i ); // Entero i encargado de devolver el vector

}		/* -----  end of function func_call  ----- */

int main ( int argc, char *argv[] ) {
  
  int *A, A_size, partner;
  
  printf ( "Size of vector: ");
  scanf( "%d", &A_size );
  
  A = (int *)malloc(A_size * sizeof(int));

  for ( int i = 0; i < A_size; i++ ) {
    printf( "Number(%d): ", i );
    scanf( "%d", &A[i] );
  }
  
  partner = func_call ( A, A_size );
  if ( partner == -1)
    printf ("Vector demasiado pequenio(minimo 3)\n");
  else
    printf( "Encontrada(s) %d pareja(s)\n", partner );
  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */





