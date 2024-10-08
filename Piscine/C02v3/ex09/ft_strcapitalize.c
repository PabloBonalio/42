/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:05:42 by pperez-a          #+#    #+#             */
/*   Updated: 2024/06/03 23:04:20 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_alphanumeric(char str)
{
	if (((str >= '0') && (str <= '9')) || ((str >= 'A') && (str <= 'Z'))
		|| ((str >= 'a') && (str <= 'z')))
		return (1);
	else
		return (0);
}

int	ft_str_is_uppercase(char str)
{
	if (str >= 65 && str <= 90)
		return (1);
	else
		return (0);
}

int	ft_str_is_lowercase(char str)
{
	if (str >= 97 && str <= 122)
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((ft_is_alphanumeric(str[i])) && (ft_str_is_lowercase(str[i])))
			str[i] -= 32;
		while (ft_is_alphanumeric(str[i]))
		{
			if (ft_str_is_uppercase(str[i + 1]))
			{
				str[i + 1] += 32;
			}
			i++;
		}
		i++;
	}
	return (str);
}
/*
int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	printf("abajo mi frase\n%s", ft_strcapitalize(argv[1]));
	return (0);
}
*/
