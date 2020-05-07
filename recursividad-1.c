#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int r_func (int *vector, int v_size, int i, int j, int count,
            int maxCount, int maxValue)
{
  //Asignamos la moda aqui
  if (count > maxCount)
  {
    maxCount = count;
    maxValue = vector[i];
  }
  //Si i llega a la ultima posicion del vector devulve la moda
  if (i == v_size - 1)
    return maxValue;
  //Cuando j alcance el mismo valor que el tamano restauramos j = 0
  if (j == v_size)
    return r_func (vector, v_size, i+1, 0, 0, maxCount, maxValue);
  //si j < tamano comprueba si se repiten valores, aumentando en 1 j
  if (j < v_size)
  {
    if (vector[j] == vector[i])
      return r_func (vector, v_size, i, j+1, count+1, maxCount, maxValue);
    else
      return r_func (vector, v_size, i, j+1, count, maxCount, maxValue);
  }
}
int func_call (int *vector, int v_size)
{
  int i = 0, j = 0;
  int count = 0, maxCount = 0, maxValue = 0;
  if (v_size == 0)
    return 0;
  if (v_size == 1)
    return vector[0];
  else
    return r_func (vector, v_size, i, j, count, maxCount, maxValue);
}

int main(int argc, char *argv[])
{
  int *vector, v_size, moda;
  printf("Tamano del vector: ");
  scanf("%d", &v_size);

  vector = (int *)malloc(v_size * sizeof(int));
  
  for (int i = 0; i < v_size; i++)
  {
    printf("Valor: ");
    scanf("%d", &vector[i]);
  }

  moda = func_call(vector, v_size);
  printf("%d", moda);
  return 0;
}
