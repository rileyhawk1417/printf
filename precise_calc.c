#include "main.h"
#include <ctype.h>

/**
 * precise_calc - Calculates the precise for printing
 * @fmt: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: precise.
 */
int precise_calc(const char *fmt, int *i, va_list list) {
  int curr_i = *i + 1;
  int precise = -1;

  if (fmt[curr_i] != '.')
    return (precise);

  precise = 0;

  for (curr_i += 1; fmt[curr_i] != '\0'; curr_i++) {
    if (isdigit(fmt[curr_i])) {
      precise *= 10;
      precise += fmt[curr_i] - '0';
    } else if (fmt[curr_i] == '*') {
      curr_i++;
      precise = va_arg(list, int);
      break;
    } else
      break;
  }

  *i = curr_i - 1;

  return (precise);
}
