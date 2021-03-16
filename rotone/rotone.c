#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

static void	ft_rotone(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]))
		{
			if (str[i] == 90 || str[i] == 122)
				ft_putchar(str[i] - 25);
			else
				ft_putchar(str[i] + 1);
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
	ft_rotone(str);
	return (0);
}
