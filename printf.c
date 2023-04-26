#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

/**
 *  _printf - produces output according to a format
 *  @format: pointer to a character string
 *  Return: count of characters printed
 */

int _printf(const char *format, ...)
{
	va_list list;
	int i, j, k, cv, dv, temp, dd, nd, count = 0;
	char *sv;

	va_start(list, format);
	if (format == NULL || strcmp(format, "%") == 0)
		exit(1);
	for (i = 0; format[i] != '\0'; i++)
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					cv = va_arg(list, int), putchar(cv), count++;
					break;
				case 's':
					sv = va_arg(list, char*);
					if (sv == NULL)
					write(STDOUT_FILENO, "null", 4), count += 4;
					for (j = 0; sv[j] != '\0'; j++)
						putchar(sv[j]), count++;
					break;
				case 'd':
				case 'i':
					dv = va_arg(list, int);
					nd = 0, temp = dv;
					while (temp != 0)
						nd++, temp /= 10;
					if (dv < 0)
						putchar('-'), dv = -dv;
					for (k = nd - 1; k >= 0; k--)
					       dd = dv / (int) pow(10, k) % 10, putchar('0' + dd);
					break;
				case '%':
					putchar('%'), count++;
					break;
					default:
					putchar('%'), putchar(format[i]), count += 2;
					break;
			}
		}
		else
		putchar(format[i]), count++;
	va_end(list);
	return (count);
}
