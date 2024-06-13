/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:38:03 by pperez-a          #+#    #+#             */
/*   Updated: 2024/06/12 22:52:58 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*ptr_to_str;
	int		len;
	int		i;

	len = ft_strlen(src);
	ptr_to_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr_to_str)
		return (NULL);
	else
		return (*ptr_to_str);
	while (src[i])
	{
		ptr_to_str[i] = src[i];
		i++;
	}
	return (ptr_to_str);
}
