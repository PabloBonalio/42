/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:23:16 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/03 15:37:19 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char *message)
{
	ft_printf("Error: %s\n", message);
	return (0);
}

int	main_error(char *message)
{
	ft_printf("Error: %s\n", message);
	return (1);
}
