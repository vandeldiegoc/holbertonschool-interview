#include "palindrome.h"
#include <stdio.h>

/**
 * is_palindrome - checks whether or not a given integer is a palindrom
 * @n: is the number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
int palin = 0, rever = 0;
unsigned long array[1024], num = n;

while (num != 0)
{
array[palin++] = num % 10;
num = num / 10;
}
palin--;
for (; palin > rever; palin--, rever++)
{
if (array[palin] != array[rever])
return (0);
}
return (1);
}
