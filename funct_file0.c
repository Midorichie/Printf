/***************CHARACTER*************************/
#include "main.h"
/**
 * print_char - prints a single character
 * @types: List of arguments
 * @buffer: Buffer array of printing
 * @flags: Flags for formatting
 * @width: For the Width
 * @precision: For precision
 * @size: For the size
 * Return: Number of characters to be printed
 */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/*******************STRING**********************/

/**
 * print_string - Prints out a string
 * @types: Arrangement of Arguments
 * @buffer: Buffer array of printing
 * @flags: Calculate active flags for formatting
 * @width: For width
 * @precision: For precision
 * @size: For size
 * Return: Number of characters to be printed
 */
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, x;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = " ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (x = width - length; x > 0; x--)
				write(1, "", 1);
			return (width);
		}
		else
		{
			for (x = width - length; x > 0; x--)
				write(1, "", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/*************************%%**********************/
/**
 * print_percent - Prints a percent sign to the output
 * @types: List of Arguments
 * @buffer: Buffer array for printing
 * @flags: Flags for formating
 * @width: For width
 * @precision: For precision
 * @size: For size specifier
 * by Hammed Yakub and Kolawole Tella
 * Return: Number of characters printed
 */

int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/***************************INT(I)*******************/
/**
 * print_int - prints an integer
 * @types: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Flags for formatting
 * @width: For width
 * @precision: For precision
 * @size: For size
 * Return: Number of characters to be printed
 */

int print_int(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[x--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[x--] = (num % 10) + '0';
		num /= 10;
	}

	x++;

	return (write_number(is_negative, x, buffer, flags, width, precision, size));
}

/**********************BINARY****************************/
/**
 * print_binary - prints binary
 * @types: List of Arguments
 * @buffer: Buffer array for printing
 * @flags: Flags for formatting
 * @width: For width
 * @precision: For precision
 * @size: For size
 * Return: Number of characters printed
 */

int print_binary(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	unsigned int b, c, n, sum;
	unsigned int a[2];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	b = va_arg(types, unsigned int);
	c = 2147483648; /* (2^31) */
	a[0] = b / c;
	for (n = 1; n < 32; n++)
	{
		c /= 2;
		a[n] = (b / c) % 2;
	}
	for (n = 0, sum = 0, count = 0; n < 32; n++)
	{
		sum += a[n];
		if (sum || n == 31)
		{
			char z = '0' + a[n];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
