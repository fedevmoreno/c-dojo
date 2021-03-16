/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "nothing" "This sentence hides nothing" | cat -e
nothig$
$>./inter | cat -e
$
*/

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

int	ft_strchr(char *s, int c)
{
	while(*s)
		if (*s++ == c)
			return (1);
	return (0);
}

int	main(int argc, const char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	char	*s1;
	char	*s2;
	char	*inter;
	int	i;
	int	j;

	s1 = (char *)argv[1];
	s2 = (char *)argv[2];
	inter = (char *)malloc(sizeof(char) * (ft_strlen((char *)argv[1]) + ft_strlen((char *)argv[2]) + 1));
	if (!inter)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(s2, s1[i]) && !(ft_strchr(inter, s1[i])))
		{
			inter[j] = s1[i];
			j++;
		}
		i++;
	}

	inter[j] = '\0';
	ft_putstr(inter);
	write(1, "\n", 1);
	free(inter);
	inter = NULL;
	return (0);
}
