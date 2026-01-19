/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 23:06:21 by mcarapie          #+#    #+#             */
/*   Updated: 2025/12/01 17:09:44 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*str;

	while (*lst)
	{
		str = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = str;
	}
	*lst = NULL;
}
