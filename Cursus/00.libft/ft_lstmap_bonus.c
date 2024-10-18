/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:31:05 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/09 18:41:08 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux_list;
	t_list	*new_node;
	void	*new_content;

	aux_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = malloc(sizeof(t_list));
		if (!new_node)
		{
			if (new_content)
				del(new_content);
			ft_lstclear(&aux_list, del);
			return (NULL);
		}
		new_node->content = new_content;
		new_node->next = NULL;
		ft_lstadd_back(&aux_list, new_node);
		lst = lst->next;
	}
	return (aux_list);
}
