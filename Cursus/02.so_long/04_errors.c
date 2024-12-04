/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:23:16 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/04 16:41:34 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_codes.h"
#include "so_long.h"

void	error(char *message, void *to_free, int exit_code)
{
	ft_printf(2, "Error: %s\n", message);
	if (to_free)
		free(to_free);
	exit(exit_code);
}
