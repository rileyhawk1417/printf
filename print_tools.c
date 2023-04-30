#include "main.h"

int print_handler(const char *fmt, int *index, va_list list, int flag,
		int length, int precise)
{
int i, unkown_length = 0, std_out_count = -1;
fmts fmt_info[] = {{'s', print_string}};
for (i = 0; fmt_info[i].fmt != '\0'; i++)
{
if (fmt[*index] == fmt_info[i].fmt)
{ return (fmt_info[i].fn(list, flag, length, precise)); }
}

if (fmt_info[i].fmt == '\0')
{
if (fmt[*index] == '\0')
{ return (-1); }
unkown_length += write(1, "%%", 1);
if (fmt[*index - 1] == ' ')
{ unkown_length += write(1, " ", 1); }
else if (length)
{
--(*index);
while (fmt[*index] != ' ' && fmt[*index] != '%')
{ --(*index); }
if (fmt[*index] == ' ')
{ --(*index); }
return (1);
}
unkown_length += write(1, &fmt[*index], 1);
return (unkown_length);
}
return (std_out_count);
}
