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

long	pwr(long base, long exponent)
{
	int		i;
	long	result;

	result = 1;
	i = 0;
	while (i < exponent)
	{
		result *= base;
		i++;
	}
	return (result);
}

void	write_number_in_hex(long number)
{
	long	digit_count;
	long	index;
	long	copy_number;
	char	*base;

	base = "0123456789abcdef";
	if (number < 16)
		write(1, "0", 1);
	copy_number = number;
	digit_count = 1;
	while (copy_number / 16 > 0)
	{
		copy_number = copy_number / 16;
		digit_count++;
	}
	while (digit_count > 0)
	{
		index = number / pwr(16, digit_count - 1);
		write(1, base + index, 1);
		number = number % pwr(16, digit_count - 1);
		digit_count--;
	}
}

void	ft_putstr(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (' ' > str[i] || str[i] > '~')
		{
			write(1, ".", 1);
		}
		else
		{
			write(1, str + i, 1);
		}
		i++;
	}
	write(1, "\n", 1);
}

void	write_first_column(void *addr)
{
	long	digit_count;
	long	number;
	int		i;

	number = (long)addr;
	digit_count = 1;
	while (number / 16 > 0)
	{
		number = number / 16;
		digit_count++;
	}
	i = 0;
	while (i < 16 - digit_count)
	{
		write(1, "0", 1);
		i++;
	}
	write_number_in_hex((long)addr);
	write(1, ": ", 2);
}

void	*ft_print_memory(void *addr, int size)
{
	int		i;
	int		amount_of_characters;

	amount_of_characters = 16;
	while (size > 0)
	{
		if (size < 16)
			amount_of_characters = size;
		write_first_column(addr);
		i = 0;
		while (i < 16)
		{
			if (size <= 0)
				write(1, "  ", 2);
			else
				write_number_in_hex(*((char *)addr + i));
			if (i % 2 != 0)
				write(1, " ", 1);
			i++;
			size --;
		}
		ft_putstr(addr, amount_of_characters);
		addr += 16;
	}
	return (addr);
}
