/*
 * =====================================================================================
 *
 *       Filename:  ejercicio3.c
 *
 *    Description:  Recursive algorithm in the same step, the maximum and minimum
 *                  on a non-empty array.
 *
 *        Version:  1.0
 *        Created:  02/05/2020 10:29:17
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


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  r_func
 *  Description:  Returns the maximum and minum value of the array
 * =====================================================================================
 */
int *r_func ( int *v, int size_v, int *max_min, int counter ) {
  
  int temp;
  
  if ( max_min[1] > max_min[0] ) {
    temp = max_min[0];
    max_min[0] = max_min[1];
    max_min[1] = temp;
  }
  if ( counter == size_v )
    return max_min;
  if (counter < size_v ) {
    if ( v[counter] > max_min[0] )
      max_min[0] = v[counter];
    if ( v[counter] < max_min[1] )
      max_min[1] = v[counter];
    return r_func ( v, size_v, max_min, counter + 1 );
  }
}	

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  call_func
 *  Description:  Calls the recursive function 
 * =====================================================================================
 */
int *call_func ( int *v, int size_v ) {
  
  int max_min[2]; //max_min[0] -> max, max_min[1] -> min
  int counter = 0;
  max_min[0] = max_min[1] = v[0];

  if ( size_v == 0 )
    return 0;
  if ( size_v == 0 )
    return v;
  else
    return r_func ( v, size_v, max_min, counter );

}	

int main ( int argc, char *argv[] ) {
  
  int *v, size_v;
  int *max_min;
  printf("Size of vector: ");
  scanf("%d", &size_v);

  v = (int *)malloc(size_v * sizeof(int));
  
  for ( int i = 0; i < size_v; i++ ) {
    printf("Number: ");
    scanf("%d", &v[i]);
  }
  
  max_min = call_func ( v, size_v );
  
  printf("max: %d min: %d", max_min[0], max_min[1]);

  return EXIT_SUCCESS;
}
