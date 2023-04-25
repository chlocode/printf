#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

/**
 *  _printf - produces output according to a format
 *
 *  @format: pointer to a character string
 *
 *  Return: count of characters printed
 */

int _printf(const char *format, ...)
{
	va_list list;
	int i, j, count;
	char cv;
	char *sv;

	va_start(list, format);

	for (i = 0; i != '\0'; i++)
	{
		if (format[i] == '%' && format[i++] == '%')
			putchar('%');
		if (format[i] == '%' && format[i++] == 'c')
		{
			cv = va_arg(list, int);
			putchar(cv);
		}
		if (format[i] == '%' && format[i++] == 's')
		{
			sv = va_arg(list, char*);
			if (sv != NULL)
			{
				for (j = 0; j != '\0'; j++)
					putchar(sv[j]);
			}
		}
		va_end(list);
		putchar(format[i]);
	}
	count = 0;
	while (format[count])
		count++;
	return (count);
}
