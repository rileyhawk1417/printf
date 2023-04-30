#include "main.h"
#include <ctype.h>

/**
 * length_calc - Calculates the length for printing
 * @fmt: Formatted string in which to print the arguments.
 * @index: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: len.
 */
int length_calc(const char *fmt, int *index, va_list list)
{
int current_index;
int len = 0;

for (current_index = *index + 1; fmt[current_index] != '\0'; current_index++)
{
if (isdigit(fmt[current_index]))
{
len *= 10;
len += fmt[current_index] - '0';
}
else if (fmt[current_index] == '*')
{
current_index++;
len = va_arg(list, int);
break;
}
else
	break;
}

*index = current_index - 1;

return (len);
}
