/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreno <fmoreno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 01:29:00 by fmoreno           #+#    #+#             */
/*   Updated: 2021/03/08 17:51:21 by fmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		n_len;

	nbr = n;
	n_len = ft_intlen(nbr);
	str = (char *)malloc(sizeof(*str) * n_len + 1);
	if (!str)
		return (NULL);
	str[n_len--] = '\0';
	if (nbr == 0)
		str[0] = 48;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		str[n_len] = 48 + (nbr % 10);
		nbr = nbr / 10;
		n_len--;
	}
	return (str);
}
