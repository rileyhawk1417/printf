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
unsigned int result = 0;
va_list args;
va_start(args, fmt);
result = print_helper(fmt, args);
va_end(args);
return (result);
}
