/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:30:13 by pperez-a          #+#    #+#             */
/*   Updated: 2024/06/02 22:13:26 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_atoi_parse(char *argv, int *clues)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (argv[i * 2] >= '1' && argv[i * 2] <= '4')
		{
			clues[i] = argv[i * 2] - '0';
			/*printf("SE GUARDA %d\n", clues[i]);*/
		}
		else
		{
			write(1, "2error\n", 7);
			return ;
		}
		if (i < 15 && argv[i * 2 + 1] != ' ')
		{
			write(1, "3error\n", 7);
			return ;
		}
		i++;
	}
}
