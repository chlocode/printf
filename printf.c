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
	int i, j, cv, count = 0;
	char *sv;

	va_start(list, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;

			switch (format[i])
			{
				case 'c':
					cv = va_arg(list, int);
					putchar(cv);
					count++;
					break;
				case 's':
					sv = va_arg(list, char*);
					for (j = 0; sv[j] != '\0'; j++)
					{
						putchar(sv[j]);
						count++;
					}
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(format[i]);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
	}
	va_end(list);
	return (count);
}
