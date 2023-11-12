#include "main.h"
/**
 * _printf - prints output in a format
 * @format: The format of the string
 * Return: The number of characters printed, excluding null byte
 */
int _printf(const char *format, ...)
{
	int total = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			switch (*(format + 1))
			{
				case 'c':
					total += putchar(va_arg(args, int));
					break;
				case 's':
					total += _printf(va_arg(args, char *));
					break;
				case '%':
					total += putchar('%');
					break;
				default:
					total += putchar('%') + putchar(*(format + 1));
			}
			format += 2;
		}
		else
		{
			total += putchar(*format);
			format++;
		}
	}
	va_end(args);
	return (total);
}
