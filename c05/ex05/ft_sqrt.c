/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 00:33:46 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/16 21:36:25 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	digit_check(int number)
{
	int	d;

	d = number % 10;
	if (d != 9 && d != 6 && d != 5 && d != 4 && d != 1 && d != 0)
		return (0);
	else
		return (1);
}

int	ft_sqrt(int nb)
{
	long long	lower_bound;
	long long	middle;
	long long	upper_bound;
	int			i;

	if (nb <= 0 || !digit_check(nb))
		return (0);
	if (nb == 1)
		return (1);
	lower_bound = 2;
	upper_bound = nb / 2;
	i = 0;
	while (i < 100)
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
	return (0);
}

// int	ft_sqrt(int nb)
// {
// 	int	i;
// 	if (nb <= 0 || !digit_check(nb))
// 		return (0);
// 	if (nb == 1)
// 		return (1);

// 	i = 2;
// 	while (i * i < nb)
// 	{
// 		i++;
// 	}
// 	if (i * i == nb)
// 		return (i);
// 	else
// 		return (0);
// }