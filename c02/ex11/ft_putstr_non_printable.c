/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 20:29:11 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/11 20:29:11 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

// int	ft_strlen(char *str)
// {
// 	int	count;

// 	count = 0;
// 	while (str[count])
// 	{
// 		count++;
// 	}
// 	return (count);
// }

void	write_number_in_base(int number, char *base, int length_new_base)
{
	int	digit_count;
	int	index;
	int	copy_number;

	copy_number = number;
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

int	ft_str_is_printable(char c)
{
	int	is_printable;

	is_printable = 1;
	if (' ' > c || c > '~')
	{
		is_printable = 0;
	}
	return (is_printable);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_str_is_printable(str[i]))
		{
			write(1, &str[i], 1);
		}
		else
		{
			write(1, &"\\", 1);
			if (str[i] < 0)
			{
				write(1, "-", 1);
				str[i] = -str[i];
			}
			if (str[i] < 16)
				write(1, &"0", 1);
			write_number_in_base(str[i], "0123456789abcdef", 16);
		}
		i++;
	}
}
