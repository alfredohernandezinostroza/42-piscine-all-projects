/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:40:41 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/23 20:40:41 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		found_position;
	char	*result;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == to_find[0])
		{
			found_position = i;
			j = 1;
			while (str[i + 1] == to_find[j])
			{
				if (to_find[j + 2] == 0)
				{
					result = str + found_position;
					return (result);
				}
				j++;
			}
		}
		i++;
	}
	result = (char *)0;
	return (result);
}