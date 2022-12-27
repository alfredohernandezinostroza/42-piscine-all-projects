/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 01:02:13 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/24 22:08:15 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double	ft_sqrt(int nb)
{
	double	lower_bound;
	double	middle;
	double	upper_bound;
	int		i;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	lower_bound = 2;
	upper_bound = nb / 2;
	i = 0;
	while (i < 1000)
	{
		middle = (lower_bound + upper_bound) / 2;
		if (middle * middle == nb)
			return (middle);
		else if (middle * middle > nb)
			upper_bound = middle;
		else
			lower_bound = middle;
		i++;
	}
	return (middle);
}

int	ft_is_prime(int nb)
{
	int	i;

	if (nb == 2)
		return (1);
	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= (int)ft_sqrt(nb))
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
	{
		nb++;
	}
	return (nb);
}
