/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:53:58 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/05 15:38:11 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*aux_str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		aux_str = malloc(1);
		if (!aux_str)
			return (NULL);
		aux_str[0] = 0;
		return (aux_str);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	aux_str = malloc((len + 1));
	if (!aux_str)
		return (NULL);
	ft_strlcpy(aux_str, (s + start), len + 1);
	return (aux_str);
}
