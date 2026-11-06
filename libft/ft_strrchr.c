/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofdomin <sofdomin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 11:02:11 by sofdomin          #+#    #+#             */
/*   Updated: 2026/11/06 13:09:08 by sofdomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i > 0)
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i--;
	}
	if (c == str[0])
		return ((char *)&str[0]);
	return (NULL);
}

