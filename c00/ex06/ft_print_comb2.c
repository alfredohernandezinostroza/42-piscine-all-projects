/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:07:56 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/09 17:42:00 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_number(int number)
{
	if (number / 10 == 0)
	{
		ft_putchar('0');
	}
	else
	{
		ft_putchar(number / 10 + '0');
	}
	ft_putchar(number % 10 + '0');
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			print_number(i);
			ft_putchar(' ');
			print_number(j);
			if (i != 98)
			{
				write(1, &", ", 2);
			}
			else
			{
				write(1, &"\n", 2);
			}
			j++;
		}
		i++;
	}
}
