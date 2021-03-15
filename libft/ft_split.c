/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreno <fmoreno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 01:30:37 by fmoreno           #+#    #+#             */
/*   Updated: 2021/03/04 18:02:30 by fmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char *s, char c)
{
	int	count;
	int	is_word;

	count = 0;
	is_word = 0;
	while (*s)
	{
		if (is_word == 0 && *s != c)
		{
			is_word = 1;
			count++;
		}
		else if (is_word == 1 && *s == c)
			is_word = 0;
		s++;
	}
	return (count);
}

static int	ft_wordlen(char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

static void	*my_free(char **arr, int i)
{
	while (i > 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		n_of_words;
	char	**arr;
	int		i;

	if (!s)
		return (NULL);
	n_of_words = ft_wordcount((char *)s, c);
	arr = (char **)malloc((n_of_words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (n_of_words)
	{
		while (*s == c && *s != '\0')
			s++;
		arr[i] = ft_substr((char *)s, 0, ft_wordlen((char *)s, c));
		if (!arr[i])
			return (my_free(arr, i));
		s = s + ft_wordlen((char *)s, c);
		i++;
		n_of_words--;
	}
	arr[i] = NULL;
	return (arr);
}
