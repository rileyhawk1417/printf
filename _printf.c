#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/**
 * _printf - Entry point
 * @fmt: unlimited args
 * Return: int value
 * Description: Handles the arguments from
 * the main function
 */
int _printf(char *fmt, ...)
{
unsigned int result = 0, inc = 0, word_count;
va_list args;
va_start(args, fmt);
int length = 0, precise = 0;
int res = 0;
result = print_helper(fmt, args);
va_end(args);
return (result);
}
