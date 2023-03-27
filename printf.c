#include "main.h"
int _printf(const char *format, ...)
{
	char *str;
	char c;
	int i;
	int num;
	int count = 0;
	va_list args;

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
				{
				c = va_arg(args, int);
				putchar(c);
				count++;
				break;
				}
			case 's':
				{
				str = va_arg(args, char *);
				while (*str)
				{
				putchar(*str);
				str++;
				count++;
				}
				break;
				}
				case 'd':
				case 'i':
				num = va_arg(args, int);
					if (num < 0)
					{
					putchar('-');
					count++;
					num = -num;
					}
					do
					{
					putchar(num % 10 + '0');
					count++;
					num /= 10;
					}
					while (num > 0);
				break;
				case '%':
				{
				putchar('%');
				count++;
				break;
				}
				default:
				{
				putchar('%');
				putchar(format[i]);
				count += 2;
				break;
				}
		}
		}
		else
		{
		putchar(format[i]);
		count++;
		}
	}
	va_end(args);
	return (count);
}
