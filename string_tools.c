#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * TODO: Add more helper functions
 * _string_parser - Entry point
 * @string: unlimited args
 * Return: int value (printed message)
 * Description: Prints the string & counts the string
 */
int _string_parser(char *string) {
  int count = 0, result = 0, i = 0;
  char *failMsg = "(null)";
  if (string == NULL) {
    while (failMsg[i]) {
      _printer(failMsg[i]);
      i++;
    }
  } else {
    while (string[count] != '\0') {
      if (string[count] == '\0') {
        printf("Found a rat");
      }
      _printer(string[count]);
      result += 1;
      count++;
    }
  }

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
    i++;
  }
  return (i);
}
