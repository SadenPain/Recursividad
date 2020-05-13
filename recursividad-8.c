/*
 * =====================================================================================
 *
 *       Filename:  recursividad-8.c
 *
 *    Description:  En un vector de enteros se genera un «cambio de tendencia» cuando dada una
 *    secuencia creciente o decreciente de números que ocupan posiciones consecutivas
 *    del vector, el elemento que le sucede es inferior o superior respectivamente. Dado
 *    un vector de N enteros, diseñe una función recursiva que calcule el número de
 *    «cambios de tendencia» que contiene dicho vector.
 *
 *        Version:  1.0
 *        Created:  05/13/2020 05:32:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  r_func
 *  Description:  
 * =====================================================================================
 */
int r_func ( int *vector, int N, int i, int creciente, int decreciente )
{
  if ( i == N )
    return creciente + decreciente;
  else
  {
    if ( vector[i] > vector[i+1] )
      return r_func ( vector, N, i+1, creciente, decreciente+1 );
    else if ( vector[i] < vector[i+1] )
      return r_func ( vector, N, i+1, creciente+1, decreciente );
    else
      return r_func ( vector, N, i+1, creciente, decreciente );
  }
}		/* -----  end of function r_func  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  func_call
 *  Description:  
 * =====================================================================================
 */
int func_call ( int *vector, int N )
{
  if (N <= 1)
    return -1;
  else
    return r_func ( vector, N, 0, 0, 0 );
}		/* -----  end of function func_call  ----- */

int main () 
{
  int *vector, N, cambios;

  printf("Numero de elementos: ");
  scanf("%d", &N);

  vector = (int *)malloc(N *sizeof(int));

  for ( int i = 0; i < N; i++ )
  {
    printf("Elemento(%d): ", i);
    scanf("%d", &vector[i]);
  }

  cambios = func_call ( vector, N );
  printf("%d\n", cambios);
  return 0;
}

