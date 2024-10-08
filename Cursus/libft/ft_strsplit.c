/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:53:52 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/08 12:01:37 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

// Helper function to allocate and copy a word
static char	*word_dup(const char *start, size_t len)
{
	char	*word;

	word = (char *)malloc(len + 1);
	if (word)
	{
		strncpy(word, start, len);
		word[len] = '\0';
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	if (!s)
		return (NULL);

	int words = count_words(s, c);
	char **aux_str = (char **)malloc((words + 1) * sizeof(char *));
	if (!aux_str)
		return (NULL);

	int i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			const char *start = s;
			while (*s && *s != c)
				s++;
			aux_str[i++] = word_dup(start, s - start);
		}
	}
	aux_str[i] = NULL;
	return (aux_str);
};
