#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @flag: find active flags
 * @len: get length of string.
 * @precise: Precision specification
 * Return: Number of chars printed
 */
int print_string(va_list types, int flag, int len, int precise)
{
int length = 0, i;
char *str = va_arg(types, char *);

if (str == NULL)
{
str = "(null)";
if (precise >= 6)
	str = "      ";
}

while (str[length] != '\0')
	length++;

if (precise >= 0 && precise < length)
	length = precise;

if (len > length)
{
if (flag & F_MINUS)
{
write(1, &str[0], length);
for (i = len - length; i > 0; i--)
	write(1, " ", 1);
return (len);
}
else
{
for (i = len - length; i > 0; i--)
	write(1, " ", 1);
write(1, &str[0], length);
return (len);
}
}
return (write(1, str, length));
}
