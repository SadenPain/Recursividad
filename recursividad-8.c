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
 *  	   Precondicion: Recibe los valores inciales para el calculo de los cambios de tendencia
 *  	   Postcondicion: Devuelve el numero de cambios de tendecia en el vector dado	
 * =====================================================================================
 */
int r_func ( int *vector, int N, int i, int cambios, int tendencia )
{
	//i llega al final del vector, devuelve los cambios de tendencia
  	if ( i == N-1 )
    		return tendencia; 

  	if ( vector[i] > vector[i+1] )
	{	// Si ha habido una disminucion(cambios = 2), y ahora un aumento, cambio = 0, tendencia ++
		if ( cambios == 2 )
    			return r_func ( vector, N, i+1, 0, tendencia+1);
		// si no, simplemente hay un aumento y cambio se queda en 1.
		return r_func ( vector, N, i+1, 1, tendencia );
	}
	if ( vector[i] < vector[i+1] )
	{
		// Si ha habido un aumento(cambios = 1), y ahora una disminucion, cambio = 0, tendencia ++
    		if ( cambios == 1 )
			return r_func ( vector, N, i+1, 0, tendencia+1 );
		// Si no, simplemente hay una disminucion y cambio = 2.
		return r_func ( vector, N, i+1, 2, tendencia );
	}
  	else  
		// Si no ha existido un aumento ni una disminucion, simplemente pasa a la siguiente posicion
		 return r_func ( vector, N, i+1, cambios, tendencia );
}		/* -----  end of function r_func  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  func_call
 *  	   Precondicion: Recibe el vector y el tamanio del vector
 *  	   Postcondicion: Llama a la funcion recursiva	
 * =====================================================================================
 */
int func_call ( int *vector, int N )
{
  if (N <= 1)
    return -1;
  else
    return r_func ( vector, N, 0, -1, 0); // Los tres valores 0, corresponden a i, encargada de recorrer el vector
  					// una variable cambios que sera -1, si no existe cambios, 1 si ha habido un aumento pero 
					// no disminucion, 2 si ha habido una disminucion pero no un aumento, 
					// una variable tendencia, que aumentara cada vez que cambios sea declare 0. 
}		/* -----  end of function func_call  ----- */

int main () 
{
  int *vector, N, cambios;

  printf("Numero de elementos: ");
  scanf("%d", &N);

  vector = (int *)malloc(N * sizeof(int));

  for ( int i = 0; i < N; i++ )
  {
    printf("Elemento(%d): ", i);
    scanf("%d", &vector[i]);
  }

  cambios = func_call ( vector, N );
  printf("%d\n", cambios);
  return 0;
}

