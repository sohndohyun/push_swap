/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 14:25:53 by dsohn             #+#    #+#             */
/*   Updated: 2020/09/30 17:39:51 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *temp;

	while (*lst)
	{
		temp = *lst;
		*lst = temp->next;
		ft_lstdelone(temp, del);
	}
}
