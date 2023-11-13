#include "main.h"
/**
 * printf_string - print a string
 * @arg: Argument
 * Return: The length of the string
 */
int printf_string(va_list arg)
{
	char *str;
	int a;
	int length;

	str = va_arg(arg, char *);
	if (str == NULL)
	{
		str = "(null)";
		length = _strlen(str);
		for (a = 0; a < length; a++)
			_putchar(str[a]);
		return (length);
	}
	else
	{
		length = _strlen(str);
		for (a = 0; a < length; a++)
			_putchar(str[a]);
		return (length);
	}
}
