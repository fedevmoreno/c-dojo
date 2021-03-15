/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
		ft_putchar(*s++);
}

int	ft_strchr(char *s, int c)
{
	while (*s)
		if (*s++ == c)
			return (1);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

int	main(int argc, const char **argv)
{
	if (argc != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	const char	*s1;
	const char	*s2;
	char		uni[ft_strlen(argv[1]) + ft_strlen(argv[2]) + 1];
	int			i;
	int			j;

	s1 = argv[1];
	s2 = argv[2];
	uni[0] = s1[0];
	i = 1;
	j = 1;
	while (s1[i] != '\0')
	{
		if (!(ft_strchr(uni, s1[i])))
		{
			uni[j] = s1[i];
			j++;
		}
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		if (!(ft_strchr(uni, s2[i])))
		{
			uni[j] = s2[i];
			j++;
		}
		i++;
	}
	uni[j] = '\0';
	ft_putstr(uni);
	ft_putchar('\n');
	return (0);
}
