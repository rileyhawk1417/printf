#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/**
 * TODO: Add more helper functions
 * print_helper - Entry point
 * @fmt: unlimited args
 * @args: has a va_list type
 * Return: int value
 * Description: Has flag related code & does
 * heavy lifting of the code
 */
int print_helper(char *fmt, va_list args) {
  char ch;
  int state = 0, i = 0;
  unsigned word_count = 0, inc = 0;
  for (inc = 0; fmt[inc] != '\0'; inc++) {
    if (state == 0) {
      if (fmt[inc] == '%')
        state = 1;
      else {
        _printer(fmt[inc]);
      }
    }

    else if (state == 1) {
      switch (fmt[inc]) {
      case 'c':
        ch = va_arg(args, int);
        _printer(ch);
        break;
      case 's': {
        char *string = va_arg(args, char *);
        char *fail = "(null)";
        // BUG: Extra characters when value is NULL?
        if (!va_arg(args, char *)) {
          _string_parser(fail);
        }
        int value = _string_parser(string);
        // TODO: Split off this into another function
        // int word = _printer(string[i]);
        word_count += (value - 1);
        // NOTE: If we use 1 it wont have the same length
        break;
      }
      case '%': {
        char sign = '%';
        _printer(sign);
      }
      }
      state = 0;
    }

    word_count += 1; // Counts either way flag or not
  }
  return (word_count);
}

/**
 * _printf - Entry point
 * @fmt: unlimited args
 * Return: int value
 * Description: Handles the arguments from
 * the main function
 */
int _printf(char *fmt, ...) {
  unsigned int result = 0, inc = 0, word_count;
  va_list args;
  va_start(args, fmt);
  result = print_helper(fmt, args);
  /* NOTE: This works if there is no flag in it
  for (inc = 0; fmt[inc] != '\0'; inc++) {
    if (fmt[inc] != '%') {
      _printer(&fmt[inc]);
      result += 1;
    }
    */

  va_end(args);
  return (result);
}
