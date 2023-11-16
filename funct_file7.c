#include "main.h"
/**
 * get_size - For getting the size to cast the argument
 * @format: formatted string in which to print the arguments
 * @m: List of arguments to be printed
 * Return: The size
 */
int get_size(const char *format, int *m)
{
	int curr_m = *m + 1;
	int size = 0;

	if (format[curr_m] == '1')
		size = S_LONG;
	else if (format[curr_m] == 'h')
		size = S_SHORT;

	if (size == 0)
		*m = curr_m - 1;
	else
		*m = curr_m;
	return (size);
}
