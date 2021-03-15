#include <unistd.h>

static void	fd_putchar(char c)
{
	write(1, &c, 1);
}

static int	fd_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

static void	fd_rotone(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (fd_isalpha(str[i]))
		{
			if (str[i] == 90 || str[i] == 122)
				fd_putchar(str[i] - 25);
			else
				fd_putchar(str[i] + 1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*str;

	if (argc != 2)
		return (0);
	str = argv[1];
	fd_rotone(str);
	return (0);
}
