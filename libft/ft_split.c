/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-fon <roda-fon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:44:19 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/12 11:58:56 by roda-fon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_words(char const *s, char c)
{
	char	count;
	int		in_word;

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
			in_word = 0;
		s++;
	}
	return (count);
}

static	char	*alloc_word(const char *s, char c)
{
	int		len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	word[len] = '\0';
	while (len--)
		word[len] = s[len];
	return (word);
}

static	void	free_all(char **arr, int count)
{
	while (count--)
		free(arr[count]);
	free(arr);
}

static int	add_word(char **arr, char const **s, char c, int i)
{
	arr[i] = alloc_word(*s, c);
	if (!arr[i])
		return (-1);
	while (**s && **s != c)
		(*s)++;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (add_word(arr, &s, c, i) == -1)
				return (free_all(arr, i), NULL);
			i++;
		}
		else
			s++;
	}
	arr[i] = NULL;
	return (arr);
}
