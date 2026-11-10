/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofdomin <sofdomin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:15:55 by sofdomin          #+#    #+#             */
/*   Updated: 2026/11/10 16:39:58 by sofdomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	free_all(char **arr, size_t n)
{
	while (n > 0)
	{
		n--;
		free(arr[n]);
	}
	free(arr);
}

static int	fill(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			arr[i] = ft_substr(s, 0, len);
			if (arr[i] == NULL)
			{
				free_all(arr, i);
				return (0);
			}
			i++;
			s += len;
		}
	}
	arr[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (s == NULL)
		return (NULL);
	arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	if (!fill(arr, s, c))
		return (NULL);
	return (arr);
}
