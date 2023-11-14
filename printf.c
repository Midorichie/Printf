#include "main.h"

/**
 * _printf - custom printf function
 * @format: format string
 * @...: variable number of arguments
 * Return: number of charactyers printed, excluding nul bytes
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
		}
		format++;
	}
	return (count);
}
