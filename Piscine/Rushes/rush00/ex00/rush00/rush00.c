/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:03:26 by natferna          #+#    #+#             */
/*   Updated: 2024/05/25 16:24:35 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_line(int x, char start, char middle, char end);

//on rush function we can visually decide the characters to be used
void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
		return ;
	if (y > 0)
	{
		ft_print_line(x, 'o', '-', 'o');
		y--;
	}
	while (y > 1)
	{
		ft_print_line(x, '|', ' ', '|');
		y--;
	}
	if (y > 0)
	{
		ft_print_line(x, 'o', '-', 'o');
	}
}
