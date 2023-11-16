#include "main.h"

/**
 * print_pointer - Prints the value of a ptr var
 * @types: Arg list
 * @buffer: Buffer array[]
 * @flags: Calculates active flags available
 * @width: Get width
 * @precision: Precise Specification
 * @size: Size Specifier
 *
 * Return: Num of printed chars
 *
 * AUTHORS - Hammed Yakub and Kolawole Tella
 */

int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, len = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		len++;
		}

		if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
		if (flags & F_PLUS)
		extra_c = '+', len++;
		else if (flags & F_SPACE)
		extra_c = ' ', len++;

		ind++;

		return (write_pointer(buffer, ind, len,
		width, flags, padd, extra_c, padd_start));
}


/**
 * print_non_printable - Prints ASCII codes in hexa form of non-printable char
 * @types: Arg lists
 * @buffer: Buffer array[]
 * @flags: Calculates active flags available
 * @width: Get width
 * @precision: Precise specification
 * @size: Size specifier
 *
 * Return: Num of printed chars
 */

int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int a = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[a] != '\0')
	{
		if (is_printable(str[a]))
			buffer[a + offset] = str[a];
		else
			offset += append_hexa_code(str[a], buffer, a + offset);

		a++;
	}

	buffer[a + offset] = '\0';

	return (write(1, buffer, a + offset));
}


/**
 * print_reverse - Prints strings in a reversed direction
 * @types: Arg lists
 * @buffer: Buffer arrays[]
 * @flags: Calculates active flags available
 * @width: Get width
 * @precision: Precise specification
 * @size: Size specifier
 * Return: Num of printed chars
 */

int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int a, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (a = 0; str[a]; a++)
		;

	for (a = a - 1; a >= 0; a--)
	{
		char z = str[a];

		write(1, &z, 1);
		count++;
	}
	return (count);
}


/**
 * print_rot13string - Prints a ROT13 encoded string
 * @types: Arg lists
 * @buffer: Buffer array[]
 * @flags: Calculates active flags available
 * @width: Get width
 * @precision: Precise specification
 * @size: Size specifier
 * Return: Num of printed chars
 */

int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int a, b;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (a = 0; str[a]; a++)
	{
		for (b = 0; in[b]; b++)
		{
			if (in[b] == str[a])
			{
				x = out[b];
				write(1, &x, 1);
				count++;
				break;
							}
		}
		if (!in[b])
		{
			x = str[a];
			write(1, &x, 1);
			count++;
		}
	}

	return (count);
}
