/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofy <sofy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:29:22 by sofdomin          #+#    #+#             */
/*   Updated: 2026/11/09 16:38:02 by sofy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_len(unsigned int n)
{
	size_t	len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	size_t			len;
	char			*result;

	nbr = n;
	if (n < 0)
		nbr = -nbr;
	len = num_len(nbr) + (n < 0);
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	while (len--)
	{
		result[len] = '0' + nbr % 10;
		nbr /= 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
