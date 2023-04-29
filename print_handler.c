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
  unsigned int word_count = 0, inc = 0;
  if (fmt == NULL)
    return (-1);

  for (inc = 0; fmt[inc] != '\0'; inc++) {
    if (state == 0) {
      if (fmt[inc] == '%') {
        state = 1;

        if (fmt[inc] == '%' && fmt[inc + 1] == '\0') {
          write(1, "%%", 1);
          write(1, "\n", 1);
        }
      } else {
        _printer(fmt[inc]);
        word_count++;
      }
    }

    else if (state == 1) {
      switch (fmt[inc]) {
      case 'c': {
        ch = va_arg(args, int);
        _printer(ch);
        break;
      }

      case 's': {
        int width = length_calc(fmt, &i, args);
        int precision = precise_calc(fmt, &i, args);
        int flags = flag_finder(fmt, &i);
        /* TODO: Intergrate Print Handler for ambigious chars */
        int words = print_string(args, flags, width, precision);
        i++;
        word_count += (words - 1);
        break;
      }
      case '%': {
        write(1, "%%", 1);
        break;
      }
      default: {
        _printer('%');
        _printer(fmt[inc]);
        break;
      }
      }
      state = 0;
      word_count += 1;
    }
  }
  return (word_count);
}

/**
 * _print - Entry point
 * @msg: unlimited args
 * Return: int value
 * Description: Simply prints to the screen
 */
int _printer(char msg) { return (write(1, &msg, 1)); }
