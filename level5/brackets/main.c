/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:56:45 by oukrifa           #+#    #+#             */
/*   Updated: 2017/05/16 00:30:38 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_br(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == ']')
		{
			s[i] = ' ';
			while (i >= 0)
			{
				if (s[i] == '[')
				{
					s[i] = ' ';
					break ;
				}
				if (s[i] == '(' || s[i] == '{' || (i == 0 && s[i] != '['))
				{
					write(1, "Error\n", 6);
					return ;
				}
				i--;
			}
			i = 0;
		}
		else if (s[i] == ')')
		{
			s[i] = ' ';
			while (i >= 0)
			{
				if (s[i] == '[' || s[i] == '{' || (i == 0 && s[i] != '('))
				{
					write(1, "Error\n", 6);
					return ;
				}
				else if (s[i] == '(')
				{
					s[i] = ' ';
					break ;
				}
				i--;
			}
			i = 0;
		}
		else if (s[i] == '}')
		{
			s[i] = ' ';
			while (i >= 0)
			{
				if (s[i] == '[' || s[i] == '(' || (i == 0 && s[i] != '{'))
				{
					write(1, "Error\n", 6);
					return ;
				}
				else if (s[i] == '{')
				{
					s[i] = ' ';
					break ;
				}
				i--;
			}
			i = 0;
		}
		else
			i++;
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == '[' || s[i] == '(' || s[i] == '{')
		{
			write(1, "Error\n", 6);
			return ;
		}
		i++;
	}
	write(1, "OK\n", 3);
}

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		int i = 1;
		while (i <= ac - 1)
			ft_br(av[i++]);
	}
	else
		write(1, "\n", 1);
}
