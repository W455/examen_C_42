/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 19:01:43 by oukrifa           #+#    #+#             */
/*   Updated: 2017/05/15 20:00:39 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_sub(char *s, int start, int lenght)
{
	char *sub;
	int i = -1;
	if (!(sub = (char *)malloc(sizeof(char) * (lenght + 1))))
		return (NULL);
	while (++i < lenght)
		sub[i] = s[start + i];
	sub[i] = '\0';
	return (sub);
}

int		ft_nb(char *s)
{
	int i = 0;
	int state = 1;
	int nb = 0;

	while (s[i])
	{
		if ((s[i] == '\t' || s[i] == ' ') && state == 0)
			state = 1;
		if ((s[i] != '\t' && s[i] != ' ') && state == 1)
		{
			state = 0;
			nb++;
		}
		i++;
	}
	return (nb + 1);
}

char	**ft_split(char *s)
{
	char	**tab;
	int		k = 0;
	int		i = 0;
	int j = 0;

	if (!(tab = (char **)malloc(sizeof(char *) * (ft_nb(s)))))
		return (NULL);
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		k = i;
		while (s[i] && s[i] != ' ' && s[i] != '\t')
			i++;
		tab[j] = ft_sub(s, k, i - k);
		j++;
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
	}
	tab[j] = 0;
	return (tab);
}
