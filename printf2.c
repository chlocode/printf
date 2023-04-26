#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

/**
*_printf - produces output according to a format
*
*@format: pointer to a character string
*
*Return: count of characters printed
*/
int _printf(const char *format, ...)
{
	va_list list;
	va_start(list, format);

	int count = 0;

	const char *format_ptr = format;

	while (*format_ptr)
	{
		if (*format_ptr == '%')
		{
			format_ptr++;
			if(*format_ptr == 'd' || *format_ptr == 'i')
			{
				int number = va_arg(list, int);
				int length = 1;
				if (number < 0)
				{
					write(STDOUT_FILENO, "-", 1);
					number = -number;
					length++;
				}
				int temp_copy = number;
				while (temp_copy / 10 > 0)
				{
					length++;
					temp_copy /= 10;
				}
				char *buffer = malloc(length +1);
				if (buffer == NULL)
				{
					return -1;
				}
				int buf_position = length - 1;
				while (number / 10 > 0)
				{
					buffer[buf_position--] = number % 10 + '0';
					number /= 10;
				}
				buffer[buf_position] = number % 10 + '0';
				buffer[length] = '\0';
				write(STDOUT_FILENO, buffer, length);
				count += length;
				free(buffer);
			}
		}
		else
		{
			write(STDOUT_FILENO, format, 1);
			count++;
		}
		format_ptr++;
	}
	va_end(list);
	return (count);
	
}
