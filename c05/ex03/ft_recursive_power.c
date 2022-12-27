/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 23:58:27 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/16 00:17:38 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	static int	value = 1;
	int			result;

	if (power < 0)
		return (0);
	if (power == 0)
	{
		result = value;
		value = 1;
		return (result);
	}
	if (nb == 0)
		return (0);
	value *= nb;
	return (ft_recursive_power(nb, power - 1));
}
