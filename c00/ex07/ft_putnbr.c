/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:23:15 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/09 17:42:15 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int number)
{
	int	size;
	int	copy;

	if (number == 0)
	{
		ft_putchar('0');
		return ;
	}
	size = 1;
	copy = number;
	while (copy > 0)
	{
		size *= 10;
		copy /= 10;
	}
	size /= 10;
	while (size > 0)
	{
		ft_putchar((number / size) % 10 + '0');
		size /= 10;
	}
}
