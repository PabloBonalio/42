/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:53:52 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/08 18:15:40 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static void	free_arr(char **aux_arr, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(aux_arr[i]);
		i++;
	}
	free(aux_arr);
}

static char	*new_str(const char *s, int start, int end)
{
	char	*aux_str;
	int		len;
	int		i;

	i = 0;
	len = end - start;
	aux_str = (char *)malloc((len + 1));
	if (!aux_str)
		return (NULL);
	while (i < len)
	{
		aux_str[i] = s[i + start];
		i++;
	}
	aux_str[i] = 0;
	return (aux_str);
}

static char	**split_aux(char const *s, char c, char **aux_arr, int start)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] != 0 && s[i] == c)
			i++;
		start = i;
		while (s[i] != 0 && s[i] != c)
			i++;
		if (i > start)
		{
			aux_arr[j] = new_str(s, start, i);
			if (!aux_arr[j])
			{
				free_arr(aux_arr, j);
				return (NULL);
			}
			j++;
		}
	}
	aux_arr[j] = 0;
	return (aux_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**aux_arr;
	int		start;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	aux_arr = (char **)malloc((words + 1) * sizeof(char *));
	if (!aux_arr)
		return (NULL);
	start = 0;
	aux_arr = split_aux(s, c, aux_arr, start);
	return (aux_arr);
}
