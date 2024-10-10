/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:53:24 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/09 12:00:13 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*temp;

	if (lst)
	{
		temp = *lst;
		if (!temp)
			*lst = new_node;
		else
		{
			while (temp->next)
				temp = temp->next;
			temp->next = new_node;
		}
	}
}
