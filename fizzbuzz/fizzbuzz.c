/*
 * 0 = 0
 * % 3 = fizz
 * % 5 = buzz
 * % 3 && % 5 = fizzbuzz 
 */

#include <unistd.h>

int	f_strlen(char *s)
{
	int	l;

	l = 0;
	while (*s++)
		l++;
	return (l);
}

void	f_putchar(int c)
{
	write(1, &c, 1);
}

void	f_putnumber(unsigned int n)
{
	if (n > 9)
	{
		f_putnumber(n / 10);
		f_putchar(n % 10 + '0');
	}
	else
		f_putchar(n + 48);
}

void	fizzbuzz(int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		if (i == 0)
			write(1, "0", 1);
		else if ((i % 3 == 0) && (i % 5 == 0))
			write(1, "fizzbuzz", f_strlen("fizzbuzz"));
		else if (i % 3 == 0)
			write(1, "fizz", f_strlen("fizz"));
		else if (i % 5 == 0)
			write(1, "buzz", f_strlen("buzz"));
		else
			f_putnumber(i);
		write(1, "\n", 1);
		i++;
	}
}

int	main(void)
{
	fizzbuzz(100);
	return(0);
}
