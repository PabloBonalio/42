/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:35:02 by pperez-a          #+#    #+#             */
/*   Updated: 2024/05/26 20:35:04 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_line(int x, char start, char middle, char end);

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
		return ;
	if (y > 0)
	{
		ft_print_line(x, '/', '*', '\\');
		y--;
	}
	while (y > 1)
	{
		ft_print_line(x, '*', ' ', '*');
		y--;
	}
	if (y > 0)
	{
		ft_print_line(x, '\\', '*', '/');
	}
}
