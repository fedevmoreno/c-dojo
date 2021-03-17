/* 
To replicate the strdup function.
We need malloc() function (stdlib.h).
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

static size_t	my_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*my_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (my_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int main(void)
{
	char	*s;
	char	to_copy[] = "Hello Mars!";

	s = my_strdup(to_copy);	
	printf("String copied: %s\n", s);
	free(s);
	return (0);
}

