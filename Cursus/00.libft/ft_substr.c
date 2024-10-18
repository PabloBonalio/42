/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:53:58 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/09 18:15:51 by pperez-a         ###   ########.fr       */
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
	aux_str = (char *)malloc((len + 1));
	if (!aux_str)
		return (NULL);
	ft_strlcpy(aux_str, (s + start), len + 1);
	return (aux_str);
}
