/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strcapitalize.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aantonio <aantonio@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/08/11 12:59:26 by aantonio		  #+#	#+#			 */
/*   Updated: 2022/08/11 12:59:26 by aantonio		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	is_not_alphanumeric(char *str, int i)
{
	if (str[i] < 'a' || 'z' < str[i])
	{
		if (str[i] < 'A' || 'Z' < str[i])
		{
			if (str[i] < '0' || '9' < str[i])
			{
				return (1);
			}
		}
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	if ('a' <= str[0] && str[0] <= 'z')
	{
		str[0] = str[0] - 32;
	}
	i = 1;
	while (str[i])
	{
		if ('a' <= str[i] && str[i] <= 'z' && is_not_alphanumeric(str, i - 1))
		{
			str[i] -= 32;
		}
		if ('A' <= str[i] && str[i] <= 'Z' && !is_not_alphanumeric(str, i - 1))
			str[i] += 32;
		i++;
	}
	return (str);
}
