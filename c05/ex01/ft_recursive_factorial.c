/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 23:40:14 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/15 23:57:20 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	static int	value = 1;
	int			result;

	if (nb < 0)
		return (0);
	if (nb == 0)
	{
		result = value;
		value = 1;
		return (result);
	}
	value *= nb;
	return (ft_recursive_factorial(nb - 1));
}
