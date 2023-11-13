#include "main.h"

/**
 * _printf - custom printf function
 * @format: format string
 * @...: variable number of arguments
 * Return: number of charactyers printed, excluding nul bytes
 */
int _printf(const char *format, ...)
{
	match m[] = {
		{"%c", printf_char}, {"%s", printf_string}, {"%%", print_37}
	};

	va_list args;
	int i = 0, len = 0;
	int n;

	va_start(args, format);
	if (format == NULL ||	(format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format[i] != '\0')
	{
		n = 2;
		while (n >= 0)
		{
			if (m[n]. id[0] == format[i] && m[n].id[1] == format[i + 1])
			{
				len = len + m[n].f(args);
				i = i + 2;
			}
			n--;
		}
		_putchar(format[i]);
		i++;
		len++;
	}
	va_end(args);
	return (len);
}
