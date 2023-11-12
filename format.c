#include "main.h"
/**
 * _printf - prints output in a format
 * @format: The format of the string
 * @...: variable number of argument
 * Return: The number of characters printed, excluding null byte
 */
int _printf(const char *format, ...)
{
	int chara_count = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			chara_count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				chara_count++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				chara_count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				chara_count += str_len;
			}
		}
		format++;
	}
	va_end(args);
	return (chara_count);
}
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	_printf("Hammed\n");
	_printf("%c\n", 'a');
	_printf("%s\n", "String");
	_printf("%%\n");
	return (0);
}
