#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * TODO: Add more helper functions
 * _string_parser - Entry point
 * @string: unlimited args
 * Return: int value (printed message)
 * Description: Prints the string & counts the string
 */
int _string_parser(char *string) {
  int count = 0, result = 0;
  char *failMsg = "(null)";
  int word_length;
  if (string == NULL) {
    string = failMsg;
  }
  word_length = (strlen(string) + 1);
  while (string[count] != '\0') {
    result += 1;
    count++;
  }
  /* NOTE: Does work the same as the other*/
  write(1, string, word_length);

  return (result);
}

/**
 * TODO: Add more helper functions
 * _string_count - Entry point
 * @arg: value to be counted
 * Return: int value (printed message)
 * Description: Simply prints the value given
 */
int _string_count(char arg) {
  int i = 0;
  while (arg != '\0') {
    arg++;
    i++;
  }
  return (i);
}

/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, int len, int precise) {
  int length = 0, i;
  char *str = va_arg(types, char *);

  if (str == NULL) {
    str = "(null)";
    if (precise >= 6)
      str = "      ";
  }

  while (str[length] != '\0')
    length++;

  if (precise >= 0 && precise < length)
    length = precise;

  if (len > length) {
    /* TODO: Put back flag after */
    if (1) {
      write(1, &str[0], length);
      for (i = len - length; i > 0; i--)
        write(1, " ", 1);
      return (len);
    } else {
      for (i = len - length; i > 0; i--)
        write(1, " ", 1);
      write(1, &str[0], length);
      return (len);
    }
  }

  return (write(1, str, length));
}
