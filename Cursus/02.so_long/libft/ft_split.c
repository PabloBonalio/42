/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:53:52 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/11 12:14:34 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
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

static void	free_arr(char **aux_arr, int aux_arr_index)
{
	int	i;

	i = 0;
	while (i < aux_arr_index)
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

static char	**split_aux(const char *s, char c, char **aux_arr, int start)
{
	int	s_index;
	int	aux_arr_index;

	s_index = 0;
	aux_arr_index = 0;
	while (s[s_index])
	{
		while (s[s_index] != 0 && s[s_index] == c)
			s_index++;
		start = s_index;
		while (s[s_index] != 0 && s[s_index] != c)
			s_index++;
		if (s_index > start)
		{
			aux_arr[aux_arr_index] = new_str(s, start, s_index);
			if (!aux_arr[aux_arr_index])
			{
				free_arr(aux_arr, aux_arr_index);
				return (NULL);
			}
			aux_arr_index++;
		}
	}
	aux_arr[aux_arr_index] = 0;
	return (aux_arr);
}

char	**ft_split(const char *s, char c)
{
	char	**aux_arr;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	aux_arr = (char **)malloc((words + 1) * sizeof(char *));
	if (!aux_arr)
		return (NULL);
	aux_arr = split_aux(s, c, aux_arr, 0);
	return (aux_arr);
}
