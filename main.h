#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/* NOTE: GLOBAL VARS */
/* NOTE: FLAG Values */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/*NOTE: Printing Tools */
int _printf(char *fmt, ...);
int _printer(char msg);
int print_handler(const char *fmt, int *index, va_list list, int flag,
		int length, int precise);
int print_helper(char *fmt, va_list args);

/* NOTE: String tools */
int print_string(va_list types, int flag, int len, int precise);
int flag_finder(const char *format, int *index);
int _parse_string(va_list list, const char *fmt, int *index);
/* NOTE: Format list struct */

/**
 * struct fmt - Struct op
 * @fmt: format given/char value
 * @fn: int type function
 * Description: struct that has multiple functions
 */
typedef struct fmt
{
char fmt;
int (*fn)(va_list, int, int, int);
} fmts;

/* NOTE: MISC Tools */
int length_calc(const char *fmt, int *index, va_list list);
int precise_calc(const char *fmt, int *index, va_list list);
#endif /* MAIN_H */
