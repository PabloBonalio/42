/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:49:17 by pperez-a          #+#    #+#             */
/*   Updated: 2024/06/03 23:04:13 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	counter;

	len = 0;
	counter = 0;
	while (src[len] != '\0')
		len++;
	if (size != 0)
	{
		while (src[counter] && counter < size - 1)
		{
			dest[counter] = src[counter];
			counter++;
		}
		dest[counter] = '\0';
	}
	return (len);
}
/*
int	main(int argc, char **argv)
{
	unsigned int	size;
	char			buffer[256];

	size = 78;
	if (argc != 2)
		return (0);
	printf("la string a copiar mide %d\n", ft_strlcpy(buffer, argv[1], size));
	printf("el string final es %s", buffer);
	return (0);
}
*/
