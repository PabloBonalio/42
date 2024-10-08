/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:04:19 by pperez-a          #+#    #+#             */
/*   Updated: 2024/06/09 20:12:18 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_strstr(char *str, char *to_find);
char	*ft_strcat(char *dest, char *src, char *buffer);
char	*ft_cat_zeroes(int len, char *buffer);

void	ft_hundreds_treatement(char	*buffer, char number)
{
	ft_strstr(buffer, &number);
	ft_strstr(buffer, "100");
}

void	ft_tens_treatment(char	*buffer, char number, char number2)
{
	if (number >= '2' && number <= '9')
		ft_strcat(&number, "0", buffer);
	else
		ft_strcat(&number, &number2, buffer);
}

void	ft_units_treatment(char	*buffer, char number, int number_len)
{
	ft_strstr(buffer, &number);
	if (number_len > 3)
		ft_cat_zeroes(number_len, buffer);
}
