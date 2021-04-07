/* count and return n of vowels from string */

#include <stdio.h>

int	is_vowel(int c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
		return (1);
	else
		return (0);
}

int	vowels(char *text)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (text[i] != '\0')
	{
		if (is_vowel(text[i]))
			total++;
		i++;
	}
	return (total);
}

int	main(void)
{
	char	str[] = "Hello Vowels! Hello Tincho! Hello Fede!"; 
	int	total_vowels;

	total_vowels = vowels(str);
	printf("Total of vowels in '%s' is: %d.\n", str, total_vowels);
	return (0);
}
