/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreno <fmoreno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 19:42:25 by fmoreno           #+#    #+#             */
/*   Updated: 2021/01/25 20:47:06 by fmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == 0)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		j = 0;
		if (needle[j] == haystack[i])
		{
			while (needle[j] == haystack[i + j] && (i + j < len))
			{
				j++;
				if (needle[j] == 0)
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}
