#include <unistd.h>

static void	fd_putchar(char c)
{
	write(1, &c, 1);
}

static int	fd_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

static void	fd_rotoneortwo_decry(char *sp)
{
	int		i;

	i = 0;
	while (sp[i] != '\0')
	{
		if (fd_isalpha(sp[i]) && sp[i] == (sp[i + 1] + 1))
		{
			if (sp[i] == 'B' || sp[i] == 'b')
				fd_putchar(sp[i] + 24);
			else if ((sp[i] == 'A' || sp[i] == 'a'))
				fd_putchar(sp[i] + 24);
			else
				fd_putchar(sp[i] - 2);
		}
		else if (fd_isalpha(sp[i]))
		{
			if (sp[i] == 'A' || sp[i] == 'a')
				fd_putchar(sp[i] + 25);
			else
				fd_putchar(sp[i] - 1);
		}
		else
			fd_putchar(sp[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*sp;

	if (argc != 2)
		return (0);
	sp = argv[1];
	fd_rotoneortwo_decry(sp);
	return (0);
}
