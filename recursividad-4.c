/*
 * =====================================================================================
 *
 *       Filename:  ejercicio4.c
 *
 *    Description: Calculate the escalar producto of 2 vectors of n intergers, n >= 0 
 *
 *        Version:  1.0
 *        Created:  02/05/2020 12:44:40
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
#include <math.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  r_func
 *  Description:  
 * =====================================================================================
 */
float r_func ( int product, int *v2 ) {
  if (v2[0] > 0)
    return product + r_func(product, v2[0]-1);
  else
    return product;
}		/* -----  end of function r_func  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  call_func
 *  Description:  
 * =====================================================================================
 */
float call_func ( int *v1, int *v2 ) {
  int pr_v, angl;
  
  if ( v1[1] >= v2[1] )
    angl = v1[1] - v2[1];
  else
    angl = v2[1] - v1[1];
  if ( angl == 90 )
    return 0;
  if ( v1[0] == 0 || v2[0] == 0 )
    return 0;
  else
    return r_func ( v1[0]*cos(angl), v2[0] );

}		/* -----  end of function call_func  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] ) {
  int v1[2], v2[2];
  float product;

  printf("Vector 1: ");
  printf("\nModule: ");
  scanf("%d", &v1[0]);
  printf("\nDirection(In radians): ");
  scanf("%d", &v1[1]);
  printf("\nVector 2: ");
  printf("\nModule: ");
  scanf("%d", &v2[0]);
  printf("\nDirection(In radians): ");
  scanf("%d", &v2[1]);
  
  product = call_func ( v1, v2 );
  printf("%f", product);

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

