/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:53:44 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/08 18:07:40 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux_str;

	aux_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!aux_str)
		return (NULL);
	ft_strlcpy(aux_str, s1, ft_strlen(s1) +1);
	ft_strlcat(aux_str, s2, ft_strlen(s1) + ft_strlen(s2) +1);
	return (aux_str);
}
