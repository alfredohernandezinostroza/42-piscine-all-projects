/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:51:40 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/23 23:14:16 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int	pwr(int base, int exponent)
{
	int	i;
	int	result;

	result = 1;
	i = 0;
	while (i < exponent)
	{
		result *= base;
		i++;
	}
	return (result);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

int	is_valid_base(char *base)
{
	int	base_size;
	int	i;
	int	j;

	if (!base)
		return (0);
	base_size = ft_strlen(base);
	if (base_size == 1 || base_size > 16)
		return (0);
	i = 0;
	while (i < base_size)
	{
		j = i + 1;
		while (j < base_size)
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	write_number_in_base(int number, char *base)
{
	int	digit_count;
	int	index;
	int	length_new_base;
	int	copy_number;

	copy_number = number;
	length_new_base = ft_strlen(base);
	digit_count = 1;
	while (copy_number / length_new_base > 0)
	{
		copy_number = copy_number / length_new_base;
		digit_count++;
	}
	while (digit_count > 0)
	{
		index = number / pwr(length_new_base, digit_count - 1);
		write(1, base + index, 1);
		number = number % pwr(length_new_base, digit_count - 1);
		digit_count--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (!base || *base == 0 || !is_valid_base(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr == INT_MIN)
		{
			ft_putnbr_base(INT_MAX / 10, base);
			write(1, base + (INT_MAX % 10 + 1), 1);
			return ;
		}
		else
			nbr = nbr * -1;
	}
	write_number_in_base(nbr, base);
}
