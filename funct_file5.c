#include "main.h"
/******Write handle*********/
/**
 * handle_write_char - Prints a string to the output
 * @c: Chat types
 * @buffer: Buffer array to handle print
 * @flags: calculate active flags
 * @width: get width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters to be printed
 */
int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{ /* char is stored at the left and padding at buffer's right */
	int n = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[n++] = c;
	buffer[n] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (n = 0; n < width - 1; n++)
			buffer[BUFF_SIZE - n - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - n - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - n - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/**********Write Number*************/
/**
 * write_number - Prints a String
 * @is_negative: Lists of arguments
 * @ind: char types
 * @buffer: buffer array to handle print
 * @flags: Calculate active flags
 * @width: get width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed
 */
int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width,
				precision, length, padd, extra_ch));
}
/**
 * write_num - Write a number using a buffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer array to handle print
 * @flags: check flags
 * @width: Check for width
 * @precision: Precision specification
 * @length: Length of number
 * @padd: Padding char
 * @extra_c: Extra char
 * Return: Number of printed char
 */
int write_num(int ind, char buffer[], int flags,
		int width, int precision, int length, char padd, char extra_c)
{
	int n, padd_start = 1;

	if (precision == 0 && ind == BUFF_SIZE - 2 &&
			buffer[ind] == '0' && width == 0)
		return (0);
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	while (precision > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (n = 1; n < width - length + 1; n++)
			buffer[1] = padd;
		buffer[1] = '\0';
		if ((flags & F_MINUS) && (padd == ' '))
			return (write(1, &buffer[ind], length)
					+ write(1, &buffer[1], n - 1));
		else if (!(flags & F_MINUS) && (padd == ' '))
			return (write(1, &buffer[1], n - 1)
					+ write(1, &buffer[ind], length));
		else if (!(flags & F_MINUS) && (padd == '0'))
			return (write(1, &buffer[padd_start], n - padd_start)
					+ write(1, &buffer[ind], length - (1 - padd_start)));
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}
/**
 * write_unsgnd - displays an unsigned numerical value
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array
 * @flags: Flags specifiers
 * @width: Width specifiers
 * @precision: Precision specifier
 * @size: For size
 * Return: Number of written chars
 */
int write_unsgnd(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	/* The number is stored at the buffer's right and starts at the position n */
	int length = BUFF_SIZE - ind - 1, n = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0) no char is printed */

	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (n = 0; n < width - length; n++)
			buffer[1] = padd;

		buffer[n] = '\0';

		if (flags & F_MINUS)
			/* Assign extra char to the left of the buffer[buffer>padd] */
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], 1));
		}
		else /* Assign extra char to the left side of padding [padd>buffer] */
		{
			return (write(1, &buffer[0], n) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - Write a memory address
 * @buffer: Array of chars
 * @ind: index at which the number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which paddling should start
 * Return: Number of written chars
 */
int write_pointer(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start)
{
	int n;

	if (width > length)
	{
		for (n = 3; n < width - length + 3; n++)
			buffer[n] = padd;
		buffer[n] = '\0';
		if (flags & F_MINUS && padd == ' ')
			/* Assign extra char to the left of the buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], n - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], n - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], n - padd_start) +
					write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'z';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind
				- 1));
}
