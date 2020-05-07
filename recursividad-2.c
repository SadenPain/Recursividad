#include <stdio.h>
#include <stdlib.h>

int
r_func(int cipher, int size_c, int pos, int i_size)
{
	if (pos > i_size / 2) {
		if (pos == i_size - size_c + 1)
			return cipher % 10;
		else
			return r_func(cipher / 10, size_c - 1, pos, i_size);
	} else {
		if (pos == i_size - size_c)
			return cipher % 10;
		else
			return r_func(cipher / 10, size_c - 1, pos, i_size);
	}
}

int
main(int argc, char *argv[])
{

	int		cipher    , pos, i_esime;
	printf("Introduce the integer: ");
	scanf("%d", &cipher);

	printf("What position do you want to return: ");
	scanf("%d", &pos);

	i_esime = r_func(cipher, sizeof(cipher), pos, sizeof(cipher));

	printf("%d", i_esime);

	return 0;

}
