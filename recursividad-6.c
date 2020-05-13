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
 *         Name:  r_func
 *  Description:  Si la suma de una pareja es igual a la pareja consecutiva
 *  devuelve 1, si no devuelve 0.
 * =====================================================================================
 */
int r_func ( int *v, int A_size, int i, int k, int suma )
{
  if ( i == A_size )
    return 0;
  if ( k < 2 )
  {
    suma += v[i];
    return r_func ( v, A_size, i+1, k+1, suma ); 
  }
  if ( k == 2 )
    if (suma == v[i] + v[i+1])
      return 1;
    else
      return r_func ( v, A_size, i, 0, 0 ); 
}		/* -----  end of function r_func  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  func_call
 *  Description:  Llama a la funcion recursiva
 * =====================================================================================
 */
int func_call ( int *v, int A_size ) 
{
  int suma = 0, i = 0, k = 0;
  if ( A_size <= 2 )
    return -1;
  else 
    return r_func ( v, A_size, i ,k ,suma); 

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
  printf( "%d\n", partner );
  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */





