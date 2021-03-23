#include <unistd.h>

static void	fd_putchar(char c)
{
	write(1, &c, 1);
}

static int	fd_isalphalower(int c)
{
	return (c >= 'a' && c <= 'z');
}

static int	fd_iswtfchr(int c)
{
	return (c >= '\'' && c <= '@');
}

static void	fd_rotoneorwtf_decry(char *sp)
{
	int	i;

	i = 0;
	while (sp[i] != '\0')
	{
		if (fd_isalphalower(sp[i]))
		{
			if (sp[i] == 'a')
				fd_putchar(sp[i] + 25);
			else
				fd_putchar(sp[i] - 1);
		}
		else if (fd_iswtfchr(sp[i]))
			fd_putchar(sp[i] + 58);
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
	write(1, "\n\n\n", 3);
	fd_rotoneorwtf_decry(sp);
	write(1, "\n\n\n", 3);
	return (0);
}
