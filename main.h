#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int _printf(const char *format, ...);

int _putchar(char c);

char fmt;

int (*fn)(va_list, char[], int, int, int, int);

int handle_write_char(char c, char buffer[], int flags,
		int width, int precision, int size);

typedef struct fmt fmt_t;

int convert_size_number(int n, int size);

int write_numbers(int is_negative, int x, char buffer[],
		int flags, int width, int precision, int size);

int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int print_int(va_list types, char buffer[], int flags,
		int width, int precision, int size);

int print_binary(va_list types, char buffer[], int flags,
		int width, int precision, int size);

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
void print_buffer(char buffer[], int *buff_ind);
int handle_print(const char *format, int *i, va_list args, char buffer[],
		int flags, int width, int precision, int size);

#endif
