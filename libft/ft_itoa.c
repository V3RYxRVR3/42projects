/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofdomin <sofdomin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:29:22 by sofdomin          #+#    #+#             */
/*   Updated: 2026/11/03 15:12:48 by sofdomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

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

/*int main ()
{
	char *str;
	str = ft_itoa(10000);
	
	printf("%s\n", str);
}*/