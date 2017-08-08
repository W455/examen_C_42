/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 22:47:44 by oukrifa           #+#    #+#             */
/*   Updated: 2017/05/15 22:50:02 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len(unsigned int nbr, int base)
{
	int len;

	len = 0;
	while (nbr / base > 0)
	{
		len++;
		nbr = nbr / base;
	}
	return (len + 1);
}

char	*ft_itoa10(int nbr)
{
	unsigned int nb;
	int len;
	int sign;
	int i = 0;
	char *res;

	sign = (nbr >= 0) ? 0 : 1;
	nb = (nbr >= 0) ? nbr : -nbr;
	len = ft_len(nb, 10);
	if ((res = (char *)malloc(sizeof(char) * (len + sign))) == NULL)
		return (NULL);
	if (nbr < 0)
		res[0] = '-';
	i = len + sign;
	res[i] = '\0';
	i--;
	while (i >= sign)
	{
		res[i] = '0' + nb % 10;
		nb = nb / 10;
		i--;
	}
	return (res);
}

char	*ft_itoa_base(int nbr, int base)
{
	unsigned int nb;
	int len;
	int sign;
	int i = 0;
	char *res;
	char basef[16] = "0123456789ABCDEF";

	if (base == 10)
		return (ft_itoa10(nbr));
	sign = (nbr >= 0) ? 0 : 0;
	nb = (nbr >= 0) ? nbr : -nbr;
	len = ft_len(nb, base);
	if ((res = (char *)malloc(sizeof(char) * (len + sign))) == NULL)
		return (NULL);
	if (nbr < 0)
		res[0] = '-';
	i = len + sign;
	res[i] = '\0';
	i--;
	while (i >= sign)
	{
		res[i] = basef[nb % base];
		nb = nb / base;
		i--;
	}
	return (res);
}
