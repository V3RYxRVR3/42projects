/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofdomin <sofdomin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:29:22 by sofdomin          #+#    #+#             */
/*   Updated: 2026/11/03 14:34:11 by sofdomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stduio.h>

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	unsigned int	tmp;
	char			*result;
	size_t			len;
	int				neg;

	neg = 0;
	if (n < 0)
	{
		nbr = -(unsigned int)n;
		neg = 1;
	}
	else
		nbr = n;
	len = 1;
	tmp = nbr / 10;
	while (tmp != 0)
	{
		len++;
		tmp = tmp / 10;
	}
	len += neg;
	result = malloc (len + 1);
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	while (len > 0)
	{
		len--;
		result[len] = '0' + nbr % 10;
		nbr = nbr / 10;
	}
	if (neg)
		result[0] = '-';
	return (result);
}

#include <stdio.h>

int main	(char *result);
{
	result = ft_itoa(123);
	printf("123: %s\n", result);
	free(result);

	result = ft_itoa(-123);
	printf("-123: %s\n", result);
	free(result);

	result = ft_itoa(0);
	printf("0: %s\n", result);
	free(result);

	result = ft_itoa(INT_MAX);
	printf("INT_MAX: %s\n", result);
	free(result);

	result = ft_itoa(INT_MIN);
	printf("INT_MIN: %s\n", result);
	free(result);

	return (0);
}