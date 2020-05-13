/*
 * =====================================================================================
 *
 *       Filename:  recursividad-9.c
 *       Description: 
 *      
 *        Version:  1.0
 *        Created:  13/05/2020 19:05:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  SadenPain
 *   Organization:  UCA
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int r_func ( int *vector, int size, int i, int j, int suma )
{
    if ( i == size )
        return suma;
    if ( j == i )
        return r_func ( vector, size, i+1, i, suma );
    else
        return r_func ( vector, size, i, j+1, vector[i] + vector[j] );
}

int func_call ( int *vector, int size )
{
    if (size <= 1)
        return -1;
    else
        return r_func ( vector, size, 0, 0, 0 );
}

int main ()
{
    int *vector, size, suma;

    printf("Tamanio del vector: ");
    scanf("%d", &size);

    vector = (int *)malloc(size * sizeof(int));

    for ( int i = 0; i < size; i++ )
    {
        printf("Elemento(%d): ", i);
        scanf("%d", &vector[i]);
    }

    suma = func_call ( vector, size );

    return EXIT_SUCCESS;
}


