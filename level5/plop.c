/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 19:10:28 by oukrifa           #+#    #+#             */
/*   Updated: 2017/05/22 19:20:08 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puthex(int oct, int rem)
{
	char const *s = "0123456789abcdef";

	if (rem > 1)
		ft_puthex(oct >> 4, rem -1);
	write(1, s + oct % 16, 1);
}

void	ft_putchar(unsigned char const *ptr)
{
	char c = *ptr;
	if (c >= ' ' && c <= '~')
		write(1, ptr, 1);
	else
		write(1, ".", 1);
}

void	ft_print_memory(const void *addr, size_t size)
{
	unsigned char const *ptr = addr;
	size_t i = 0;
	size_t a;

	while (i < size)
	{
		a = 0;
		while (a < 16 && a + i < size)
		{
			ft_puthex(*(ptr + i + a), 2);
			if (a % 2)
				write(1, " ", 1);
			a++;
		}
		while (a < 16)
		{
			write(1, "  ", 2);
			if (a % 2)
				write(1, " ", 1);
			a++;
		}
		a = 0;
		while (a < 16 && a + i < size)
		{
			ft_putchar(ptr + a + i);
			a++;
		}
			write(1, "\n", 1);
		i+= 16;
	}
}

int	main(void)
{
	int		tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};

	ft_print_memory(tab, sizeof(tab));
}
