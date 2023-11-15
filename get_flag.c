#include "main.h"

/**
 * get_flag - Calculates active flags available
 * @format: Formatted string in which to print the args
 * @i: take a parameter.
 *
 * Return: Flag
 * AUTHOR - Hammed Yakub and Kolawole Tella
 */

int get_flag(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int a, curr_a;
	int flag = 0;
	const char FLAG_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_a = *a + 1; format[curr_a] != '\0'; curr_a++)
	{
		for (b = 0; FLAG_CH[b] != '\0'; b++)
			if (format[curr_a] == FLAG_CH[b])
			{
				flag |= FLAG_ARR[b];
				break;
			}
		if (FLAG_CH[b] == 0)
			break;
	}
	*a = curr_a - 1;
	return (flags);
}
