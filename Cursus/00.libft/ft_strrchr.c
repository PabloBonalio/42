/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:26:32 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/08 17:49:31 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	aux_char;
	char	*aux_str;
	size_t	len;

	aux_char = (char)c;
	aux_str = (char *)s;
	len = ft_strlen(s);
	while (len + 1 > 0)
	{
		if (aux_str[len] == aux_char)
			return (&aux_str[len]);
		len--;
	}
	if (aux_str[len] == aux_char)
		return (&aux_str[len]);
	return (NULL);
}
