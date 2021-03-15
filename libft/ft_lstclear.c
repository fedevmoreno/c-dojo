/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreno <fmoreno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 18:20:18 by fmoreno           #+#    #+#             */
/*   Updated: 2021/03/01 21:07:08 by fmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_lst;
	t_list	*next_lst;

	if (lst)
	{
		current_lst = *lst;
		while (current_lst)
		{
			next_lst = current_lst->next;
			ft_lstdelone(current_lst, (del));
			current_lst = next_lst;
		}
		*lst = NULL;
	}
}
