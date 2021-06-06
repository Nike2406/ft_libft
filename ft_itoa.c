/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locus2 <locus2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:14:53 by locus2            #+#    #+#             */
/*   Updated: 2021/05/07 20:09:49 by locus2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nmblen(int n)
{
	int	ln;

	ln = 0;
	if (n < 0)
	{
		n = -n;
		ln++;
	}
	while (n > 0)
	{
		n /= 10;
		ln++;
	}
	return (ln);
}

char	*ft_itoa(int n)
{
	char	*itnb;
	int		ln;

	ln = ft_nmblen(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	itnb = (char *)malloc(sizeof(char) * ln + 1);
	if (!itnb)
		return (NULL);
	itnb[ln--] = '\0';
	if (n < 0)
	{
		itnb[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		itnb[ln] = n % 10 + 48;
		n /= 10;
		ln--;
	}
	return (itnb);
}
