/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:29:47 by pperez-a          #+#    #+#             */
/*   Updated: 2024/05/27 23:10:08 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	buffer;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		buffer = tab[i];
		tab[i] = tab[j];
		tab[j] = buffer;
		i++;
		j--;
	}
}
