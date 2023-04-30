#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
/**
 * print_helper - Entry point
 * @fmt: unlimited args
 * @args: has a va_list type
 * Return: int value
 * Description: Mainly deals with args
 */
int print_helper(char *fmt, va_list args)
{
char ch;
int state = 0, i = 0,  words = 0;
unsigned int word_count = 0, inc = 0;
if (fmt == NULL)
	return (-1);
for (inc = 0; fmt[inc] != '\0'; inc++)
{
if (state == 0)
{
if (fmt[inc] == '%')
{
state = 1;
if (fmt[inc] == '%' && fmt[inc + 1] == '\0')
{ return (-1); }
}
else
{
_printer(fmt[inc]), word_count += 1;
}
}

else if (state == 1)
{
switch (fmt[inc])
{
case 'c':
	ch = va_arg(args, int), _printer(ch), word_count += 1;
	break;
case 's':
	words = _parse_string(args, fmt, &i), i++, word_count += words;
	break;
case '%':
	write(1, "%%", 1), word_count += 1;
	break;
default:
	_printer('%'), _printer(fmt[inc]), word_count += 1 + 1;
	break;
} state = 0;
}
} return (word_count);
}

/**
 * _printer - Entry point
 * @msg: unlimited args
 * Return: int value
 * Description: Simply prints to the screen
 */
int _printer(char msg) { return (write(1, &msg, 1)); }

/**
 * _parse_string - Entry point
 * @list: list args
 * @fmt: char to be passed
 * @index: item to be processed
 * Return: int value
 * Description: prints to the screen
 */
int _parse_string(va_list list, const char *fmt, int *index)
{
int width = 0, precision = 0, flags = 0, words = 0;
width = length_calc(fmt, index, list);
precision = precise_calc(fmt, index, list);
flags = flag_finder(fmt, index);
words = print_string(list, flags, width, precision);
/* TODO: Intergrate Print Handler for ambigious chars */
return (words);
}
