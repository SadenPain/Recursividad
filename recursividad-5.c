/*
 * =====================================================================================
 *
 *       Filename:  recursividad-5.c
 *
 *    Description:  Dado un vector ordenado crecientemente A[1..n], n>=1, calcula
 *    la forma recursiva la longitud de la escalera mas larga, es decir, la longitud
 *    de la secuencia mas larga de valores consecutivos que se encuentre en A.
 *
 *        Version:  1.0
 *        Created:  05/03/2020 10:52:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: SadenPain
 *   Organization: Universidad de Cadiz
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  r_func (int *v, int size_v, int counter, int max_counter)
 *  Description:  Calculate and returns the maximum long scale in array
 * =====================================================================================
 */
int r_func (int *v, int size_v, int counter, int max_counter, int i) { 
  
  if (counter > max_counter)
    max_counter = counter;

  if ( i == size_v ) 
    return max_counter;

  if (v[i] == v[i-1] + 1) 
    return r_func ( v, size_v, counter+1, max_counter, i+1);
  else 
    return r_func ( v, size_v, 1, max_counter, i+1);
}		/* -----  end of function r_func ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  func_call
 *  Description:  Call the final recursive function
 * =====================================================================================
 */
int func_call (int *v, int size_v) {
  
  int i = 1, counter = 1, max_counter = 0; 

  if ( size_v == 0)
    return 0;
  if ( size_v == 1 )
    return v[0];
  else 
    return r_func ( v, size_v, counter, max_counter, i );
}		/* -----  end of function func_call  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  Main function of the program
 * =====================================================================================
 */
int main (int argc, char *argv[]) {
  int *v, size_v, longi;

  printf("Tamanio del vector: ");
  scanf("%d", &size_v);

  for ( int i = 0; i < size_v; i++) {
    printf("Number(%d): ", i);
    scanf("%d", &v[i]);
  }
  
  longi = func_call(v, size_v);
  printf("%d", longi); 

  return 0;
}
