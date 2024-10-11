/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:53:24 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/11 16:24:56 by pperez-a         ###   ########.fr       */
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
int	main(void)
{
	t_list **head;

	head = NULL;	
	int content = 42;
	ft_lstadd_back(head, ft_lstnew(&content));
}
