/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:31:22 by pperez-a          #+#    #+#             */
/*   Updated: 2024/06/09 20:48:31 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	*ft_strstr(char *str, char *to_find);
char	*ft_strcat(char *dest, char *src);
char	*ft_cat_zeroes(int len);
void	ft_hundreds_treatement(char *buffer, char number);
void	ft_tens_treatment(char *buffer, char number, char number2);
void	ft_units_treatment(char *buffer, char number, int number_len);
void	ft_realloc(uint64_t increase, int number_len, char *argv);

void	ft_number_sort(char *char_number, int number_len, char *buffer, int i)
{
	while (number_len > 0)
	{
		if (char_number[i] == '0')
		{
			i++;
			number_len--;
		}
		if (number_len % 3 == 0)
			ft_hundreds_treatement(buffer, char_number[i]);
		if (number_len % 3 == 1)
			ft_units_treatment(buffer, char_number[i], number_len);
		if (number_len % 3 == 2)
		{
			ft_tens_treatment(buffer, char_number[i], char_number[i + 1]);
			if (char_number[i] == '1')
			{
				i++;
				number_len--;
			}
		}
		i++;
		number_len--;
	}
}

int	ft_number_len(char *number)
{
	int	len;

	len = 0;
	while (number[len] != '\0')
	{
		len++;
	}
	return (len);
}

int	main(int argc, char **argv)
{
	int	number_len;

	if (argc < 1)
		return (1);
	number_len = ft_number_len(argv[1]);
	ft_realloc(1, number_len, argv[1]);
	return (0);
}
