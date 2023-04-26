#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 *  _printf - produces output according to a format
 *  @format: pointer to a character string
 *  Return: count of characters printed
 */

int _printf(const char *format, ...)
{
	va_list list;
	int i, j, cv, count = 0;
	char *sv;

	va_start(list, format);

	if (format == NULL)
		exit(1);

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
					if (sv == NULL)
					{
						write(STDOUT_FILENO, "(null)", 6);
						count += 6;
					}
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
				case 'd':
				case 'i':
				{
					int number = va_arg(list, int);
					length = 1;
					sign = 0;
					/*for negative numbers*/
					if (number < 0)
					{
						sign = 1;
						write(1, "-", 1);
						number = -number;
					}
					tem_copy = number;
					while (tem_copy / 10 > 0)
					{
						length++;
						tem_copy /= 10;
					}
					if (sign)
						++length;
					buffer = malloc(length + 1);
					if (buffer == NULL)
					{
						return (-1);
					}
					buf_position = length - 1;
					while (number / 10 > 0)
					{
						buffer[buf_position--] = (number % 10) + '0';
						number /= 10;
					}
					buffer[buf_position] = number % 10 + '0';
					buffer[length] = '\0';
					write(STDOUT_FILENO, buffer, length);
					count += length;
					free(buffer);
					break;
				}
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
