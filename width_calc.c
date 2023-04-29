#include "main.h"
#include <ctype.h>

/**
 * length_calc - Calculates the len for printing
 * @fmt: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: len.
 */
int length_calc(const char *fmt, int *i, va_list list) {
  int curr_i;
  int len = 0;

  for (curr_i = *i + 1; fmt[curr_i] != '\0'; curr_i++) {
    if (isdigit(fmt[curr_i])) {
      len *= 10;
      len += fmt[curr_i] - '0';
    } else if (fmt[curr_i] == '*') {
      curr_i++;
      len = va_arg(list, int);
      break;
    } else
      break;
  }

  *i = curr_i - 1;

  return (len);
}
