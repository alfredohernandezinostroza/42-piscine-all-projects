/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:57:49 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/09 14:50:44 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_int_size(int number)
{
	int	size;

	size = 0;
	if (number == 0)
	{
		return (1);
	}
	while (number > 0)
	{
		number = number / 10;
		size++;
	}
	return (size);
}

int	to_int(const char *str)
{
	int	number;
	int	multiplier;
	int	size;
	int	i;

	number = 0;
	multiplier = 1;
	size = 0;
	i = 0;
	while (*(str + i) != 0)
	{
		size++;
		i++;
	}
	i = size;
	while (i > 0)
	{
		number = number + ((str[i - 1] - '0') * multiplier);
		multiplier = multiplier * 10;
		i--;
	}
	return (number);
}

void	to_str(int number, char *pos, int size)
{
	int	i;
	int	remainder;

	i = 0;
	while (i < size)
	{
		remainder = number % 10;
		pos[size - 1 - i] = remainder + '0';
		number = number / 10;
		i++;
	}
}

int	digits_are_ordered(int number)
{
	int	size;
	int	current_reminder;
	int	digits_are_ordered;
	int	i;

	digits_are_ordered = 1;
	size = get_int_size(number);
	i = 0;
	while (i < size - 1)
	{
		current_reminder = number % 10;
		if (current_reminder <= (number / 10) % 10)
		{
			digits_are_ordered = 0;
			break ;
		}
		number = number / 10;
		i++;
	}
	return (digits_are_ordered);
}

void	ft_print_comb(void)
{
	int			n;
	static char	numbers[4] = "012";
	int			number_as_int;

	n = 3;
	write(1, numbers, n);
	number_as_int = to_int(numbers) + 1;
	while (!digits_are_ordered(number_as_int))
	{
		if (get_int_size(number_as_int) > n)
		{
			numbers[0] = '0';
			numbers[1] = '1';
			numbers[2] = '2';
			write(1, &"\n", 1);
			return ;
		}
		number_as_int++;
	}
	write(1, &", ", 2);
	to_str(number_as_int, numbers, n);
	ft_print_comb();
}
