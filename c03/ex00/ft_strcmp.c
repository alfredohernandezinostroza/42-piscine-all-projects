/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:59:30 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/13 10:59:30 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	get_str_size(char *str)
{
	int	size;

	size = 0;
	while (str[size] != 0)
	{
		size++;
	}
	return (size);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	result;
	int	size1;
	int	size2;
	int	i;

	size1 = get_str_size(s1);
	size2 = get_str_size(s2);
	i = 0;
	result = 0;
	while (i <= size1)
	{
		result = s1[i] - s2[i];
		if (result != 0 || i > size2)
			break ;
		i++;
	}
	return (result);
}
