#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/*NOTE: Printing Tools */
int _printf(char *fmt, ...);
int _printer(char msg, int length);
int print_handler(const char *fmt, int *index, va_list list, int length,
                  int precise);

/* NOTE: String tools */
int _string_parser(char *string);
int _string_count(char arg);
int print_string(va_list types, int len, int precise);

/* NOTE: Format list struct */

typedef struct fmt

{
  char fmt;
  int (*fn)(va_list, int, int);
} fmts;

/* NOTE: MISC Tools */
int length_calc(const char *fmt, int *i, va_list list);
int precise_calc(const char *fmt, int *i, va_list list);
#endif /* MAIN_H */
