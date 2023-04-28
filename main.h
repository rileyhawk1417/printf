#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(char *fmt, ...);
int _printer(char msg);

/* NOTE: String tools */
int _string_parser(char *string);
int _string_count(char arg);
#endif /* MAIN_H */
