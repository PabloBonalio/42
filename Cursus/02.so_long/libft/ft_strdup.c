/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:04:50 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/08 14:45:43 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		len;

	len = ft_strlen(s) + 1;
	new_str = malloc(len);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s, len);
	return (new_str);
}
