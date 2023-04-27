<<<<<<< HEAD
#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

=======
#include <stdarg.h>
#include <stdio.h>
/**
 * print_helper - Entry point
 * @fmt: unlimited args
 * @args: has a va_list type
 * Return: int value
 * Description: Has flag related code & does
 * heavy lifting of the code
 */
int print_helper(const char *fmt, va_list args)
{
char *string;
char ch;
int state = 0;
while (*fmt)
{
if (state == 0)
	if (*fmt == '%')
		state = 1;
else
	putchar(*fmt);

else if (state == 1)
{
switch (*fmt)
{
case 'c':
	ch = va_arg(args, int);

	putchar(ch);
	break;
case 's':
	string = va_arg(args, char *);
	while (*string)
	{
		putchar(*string++);
	} break;
}
state = 0;
} fmt++;
}
return (*fmt);
}

/**
 * _printf - Entry point
 * @fmt: unlimited args
 * Return: int value
 * Description: Handles the arguments from
 * the main function
 */
int _printf(const char *fmt, ...)
{
int result = 0;
va_list args;
va_start(args, fmt);
result = print_helper(fmt, args);
va_end(args);
return (result);
}
>>>>>>> 415195e96a8895fd26ae24736957c9e65b9026d6
