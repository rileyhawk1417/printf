#include "main.h"
#include <ctype.h>

/**
 * precise_calc - Calculates the precise output for printing
 * @fmt: Formatted string in which to print the arguments
 * @index: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: precise.
 */
int precise_calc(const char *fmt, int *index, va_list list)
{
int current_index = *index + 1;
int precise = -1;

if (fmt[current_index] != '.')
	return (precise);

precise = 0;

for (current_index += 1; fmt[current_index] != '\0'; current_index++)
{
if (isdigit(fmt[current_index]))
{
precise *= 10;
precise += fmt[current_index] - '0';
}
else if (fmt[current_index] == '*')
{
current_index++;
precise = va_arg(list, int);
break;
}
else
{ break; }
}

*index = current_index - 1;

return (precise);
}
