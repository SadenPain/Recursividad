/*
 * =====================================================================================
 *
 *       Filename:  recursividad-7.c
 *
 *    Description:  Algoritmo que calcule de forma recursiva la suma de todos los elementos
 *    i de un vector A de n enteros que cumplen la siguiente propiedad:
 *     1≤i≤( n/2 ) −1: A [ i ] >A [ 2∗i ] ∧A [ i ] >A [ 2∗i+1 ] 
 *
 *        Version:  1.0
 *        Created:  05/13/2020 04:52:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Precondicion:
 * 
 * Postcondicion:
 *
 */
int r_func ( int *A, int n, int i, int suma )
{
  if ( i == n )
    return suma;
  if ( i <= n )
  {
    if ( (A[i] > A[2*i+1]) && (A[i] > A[(2*i)+2]))
      return r_func (A, n, i+1, suma + A[i]);
    else
      return r_func (A, n, i+1, suma );
  }
}

int func_call (int *A, int size )
{
  if ( size <= 3 )
    return -1;
  else
    return r_func ( A, size/2+size%2-1, 0, 0 );
}

int main () 
{
  int *A, size, suma;

  printf("Numero de elementos: ");
  scanf("%d", &size);

  A = (int *)malloc((size) * sizeof(int));

  for (int i = 0; i < size; i ++)
  {
    printf("Elemento(%d): ", i);
    scanf("%d", &A[i]);
  }

  suma = func_call (A, size);
  printf("%d", suma);

  return 0;
}
