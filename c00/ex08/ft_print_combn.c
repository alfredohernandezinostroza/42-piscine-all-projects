/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:37:55 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/09 17:42:12 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// int	get_str_size(const char *str)
// {
// 	int	size;
// 	int	i;

// 	size = 0;
// 	i = 0;
// 	while (*(str + i) != 0)
// 	{
// 		size++;
// 		i++;
// 	}
// 	return (size);
// }

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

// const char	*to_str(int number)
// {
// 	int	i;
// 	int	size;
// 	int	remainder;
// 	static char	converted[11];

// 	i = 0;
// 	while (i <= 10)
// 	{
// 		converted[i] = '0';
// 		i++;
// 	}
// 	size = get_int_size(number);
// 	converted[size] = 0;
// 	i = 0;
// 	while (i < size)
// 	{
// 		remainder = number % 10;
// 		converted[size - 1 - i] = remainder + '0';
// 		number = number / 10;
// 		i++;
// 	}
// 	return (converted);
// }

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

void	ft_print_combn(int n)
{
	static char	numbers[10] = "012345678";
	int			number_as_int;
	int			i;

	numbers[n] = 0;
	write(1, numbers, n);
	number_as_int = to_int(numbers) + 1;
	while (!digits_are_ordered(number_as_int))
	{
		if (get_int_size(number_as_int) > n)
		{
			i = 0;
			while (i < 9)
			{
				numbers[i] = i + '0';
				i++;
			}
			write(1, &"\n", 1);
			return ;
		}
		number_as_int++;
	}
	write(1, &", ", 2);
	to_str(number_as_int, numbers, n);
	ft_print_combn(n);
}
