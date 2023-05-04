#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	int a[2];
	int *p;

	a[2] = 1024;
	p = &n;
	/*
	*write your line of code here.
*Remember:
*- you are not allowed to use
*- you are not allowed to modi
*- You can only write one stat
*- You are not allowed to use
*- You are not allowed to code
*- Your code should be written
*- Do not remove anything from
*- and don't change anything b
*- You are allowed to use the
*/
*(p + 2) = 98;
  /* ...so that this prints 98\n */
printf("a[2] = %d\n", a[2]);
return (0);
}
