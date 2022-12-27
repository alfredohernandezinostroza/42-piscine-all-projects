/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:37:43 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/15 15:48:01 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nb);

void	ft_neg_putnbr(int nb)
{
	write(1, "-", 1);
	if (nb == INT_MIN)
	{
		ft_putnbr(INT_MAX / 10);
		write(1, "8", 1);
	}
	else
	{
		nb = -1 * nb;
		ft_putnbr(nb);
	}
}

void	ft_putnbr(int nb)
{
	long		pwr;
	int			nb_size;
	char		digit;

	if (nb < 0)
	{
		ft_neg_putnbr(nb);
		return ;
	}
	pwr = 1;
	nb_size = 1;
	while (pwr <= nb / 10)
	{
		pwr *= 10;
		nb_size++;
	}
	while (nb_size > 0)
	{
		digit = ((nb / pwr) % 10) + '0';
		pwr = pwr / 10;
		write(1, &digit, 1);
		nb_size--;
	}
}
