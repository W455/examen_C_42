/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 03:34:23 by oukrifa           #+#    #+#             */
/*   Updated: 2017/05/18 19:05:37 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list		*sort_list(t_list *begin_list, int (*cmp)(int, int))
{
	t_list	*tmp;
	int		stock;

	if (!begin_list)
		return (0);
	tmp = begin_list;
	while (tmp->next)
	{
		if (cmp(tmp->data, (tmp->next)->data) != 0)
		{
			stock = tmp->data;
			tmp->data = (tmp->next)->data;
			(tmp->next)->data = stock;
			tmp = begin_list;
		}
		else
			tmp = tmp->next;
	}
	return (begin_list);
}
