/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:03:50 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/23 23:14:05 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>

int	pwr10(int exponent)
{
	int	i;
	int	result;

	result = 1;
	i = 0;
	while (i < exponent)
	{
		result *= 10;
		i++;
	}
	return (result);
}

int	get_number(char *start, int pwr)
{	
	int	i;
	int	number;

	number = 0;
	i = 0;
	while (pwr != 0)
	{
		number += (*(start + i) - '0') * pwr;
		pwr /= 10;
		i++;
	}
	return (number);
}

int	count_signs(char *str, char *start)
{
	int	sign;

	sign = 1;
	while (str < start)
	{
		if (*(str) == '-')
		{
			sign *= -1;
		}
		str++;
	}
	return (sign);
}

int	ft_atoi(char *str)
{
	int		i;
	char	*start;
	char	*end;
	int		number;
	int		pwr;

	i = 0;
	while (!('0' <= str[i] && str[i] <= '9'))
	{
		i++;
	}
	start = str + i;
	i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		i++;
	}
	end = str + i;
	pwr = pwr10((int)(end - start - 1));
	number = get_number(start, pwr);
	return (count_signs(str, start) * number);
}
