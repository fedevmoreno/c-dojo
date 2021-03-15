/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 01:30:25 by fmoreno           #+#    #+#             */
/*   Updated: 2021/02/09 01:30:29 by fmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*pos;

	i = 0;
	pos = 0;
	while (s[i])
	{
		if (s[i] == c)
			pos = (char *)s + i;
		i++;
	}
	if (pos)
		return (pos);
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}
