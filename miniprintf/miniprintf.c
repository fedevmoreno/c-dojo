#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int	miniprintf(const char *fmt, ...)
{
	va_list	args;
	int		len;
	char	*str;

	len = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (*(++fmt) == 's')
			{
				str = va_arg(args, char *);
				ft_putstr_fd(str, 1);
				len = len + (int)ft_strlen(str);
				fmt++;
			}
		}
		ft_putchar_fd(*fmt++, 1);
		len++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	char	s[] = "Mars!";
	printf("\n***MINIPRINTF***\n\n");
	miniprintf("Hello %s\n", s);
	printf("\n***PRINTF***\n\n");
	printf("Hello %s\n", s);
	return (0);
}