#include "main.h"
#include <stdio.h>
/**
 * TODO: Add more helper functions
 * _printer - Entry point
 * @msg: unlimited args
 * Return: int value (printed message)
 * Description: Simply prints the value given
 */
int _printer(char msg) {
  // TODO: have write(1, &msg[buff_size], string_length-1)
  return (write(1, &msg, 1));
}
