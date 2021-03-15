#include <unistd.h>

static void	fd_putchar(char c)
{
	write(1, &c, 1);
}

static void	fd_putstr(char *str)
{
	while (*str)
		fd_putchar(*str++);
}

static int	fd_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len += 1;
	return (len);
}

static char	*fd_strrev(char *str)
{
	char	tmp;
	int		i;
	int		size;

	i = 0;
	size = fd_strlen(str) - 1;
	while (i < size)
	{
		tmp = str[i];
		str[i] = str[size];
		str[size] = tmp;
		size--;
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	char	*str;

	if (argc != 2)
		return (0);
	str = argv[1];
	fd_strrev(str);
	fd_putstr(str);
	return (0);
}
