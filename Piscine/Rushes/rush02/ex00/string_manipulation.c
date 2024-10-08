/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:42:57 by pperez-a          #+#    #+#             */
/*   Updated: 2024/06/09 19:32:53 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i] == to_find[j])
		{
			i++;
			j++;
			if ((to_find[j] < 48 || to_find[j] > 57))
			{
				while (str[i + 2] != '\n')
				{
					write(1, &str[i + 2], 1);
					i++;
				}
				write(1, " ", 1);
				return ;
			}
		}
		i++;
	}
}

int	ft_strcat(char *dest, char *src, char *buffer)
{
	int		i;
	char	*concat;

	i = 0;
	concat = (char *)malloc((2 + 1) * sizeof(char));
	if (concat == NULL)
	{
		return (0);
	}
	concat[0] = dest[0];
	concat[1] = src[0];
	concat[2] = '\0';
	ft_strstr(buffer, concat);
	free(concat);
	return (1);
}

int	ft_cat_zeroes(int len, char *buffer)
{
	int		i;
	char	*zeroes;

	i = 1;
	zeroes = (char *)malloc((len + 1) * sizeof(char));
	if (zeroes == NULL)
	{
		return (0);
	}
	zeroes[0] = '1';
	while (i < len)
	{
		zeroes[i] = '0';
		i++;
	}
	zeroes[len + 1] = '\0';
	ft_strstr(buffer, zeroes);
	free(zeroes);
	return (1);
}
