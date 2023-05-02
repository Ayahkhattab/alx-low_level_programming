#include "main.h"

/**
 * puts_half - Entry point
 * Description: to check if letter is uppercase
 * @str: string`
 * Return: no return
 */

void puts_half(char *str)
{
	int j = 0;
	int k;

	while (str[j] != '\0')
	{
	j++;
	}
	if (j % 2 == 1)
{
	k = (j - 1) / 2;
	k += 1;
	}

	for (; k < j; k++)
{
	_putchar(str[k]);
}
_putchar('\n');
}
