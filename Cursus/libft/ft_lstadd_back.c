#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new_node)
{
	if (lst)
	{
		t_list *temp = *lst;
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
