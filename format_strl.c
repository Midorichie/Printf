#include "main.h"
/**
 * _strlen - Prints the length of a string
 * @str: String pointer
 * Return: a
 */
int _strlen(char *str)
{
	int a;

	for (a = 0; str[a] != 0; a++)
		;
	return (a);
}
/**
 * _strlenc - Strlen - Strlen function that's applied for
 * constant character pointer str
 * @str: char pointer
 * Return: a
 */
int _strlenc(const char *str)
{
	int a;

	for (a = 0; str[a] != 0; a++)
		;
	return (a);
}
