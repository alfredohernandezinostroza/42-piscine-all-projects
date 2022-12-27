/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:31:58 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/24 22:29:01 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	arguments;
	int	c;

	arguments = argc - 1;
	while (arguments > 0)
	{
		c = 0;
		while (argv[arguments][c])
		{
			write(1, argv[arguments] + c, 1);
			c++;
		}
		write(1, "\n", 1);
		arguments--;
	}
	return (0);
}