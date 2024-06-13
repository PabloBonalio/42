/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:30:10 by pperez-a          #+#    #+#             */
/*   Updated: 2024/06/11 12:49:25 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strcmp(char *param1, char *param2)
{
	int	i;

	i = 0;
	while (param1[i] != '\0' || param2[i] != '\0')
	{
		if (param1[i] != param2[i])
			break ;
		i++;
	}
	return (param1[i] - param2[i]);
}

void	ft_param_swap(char **param1, char **param2)
{
	char	*aux;

	aux = *param1;
	*param1 = *param2;
	*param2 = aux;
}

void	ft_sort_params(char **params)
{
	int	i;
	int	j;

	i = 1;
	while (params[i + 1])
	{
		j = 1;
		while (params [j + 1])
		{
			if (ft_strcmp(params[j], params[j + 1]) > 0)
				ft_param_swap(&params[j], &params[j + 1]);
			j++;
		}
		i++;
	}
}

void	ft_print_params(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		return (1);
	ft_sort_params(argv);
	while (i < argc)
	{
		ft_print_params(argv[i]);
		i++;
	}
	return (0);
}
