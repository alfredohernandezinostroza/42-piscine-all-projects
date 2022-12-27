/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_str_is_numeric.c								:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aantonio <aantonio@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/08/11 13:29:59 by aantonio		  #+#	#+#			 */
/*   Updated: 2022/08/11 13:29:59 by aantonio		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	only_numbers;

	only_numbers = 1;
	i = 0;
	while (str[i])
	{
		if (('0' > str[i] || str[i] > '9'))
		{
			only_numbers = 0;
			break ;
		}
		i++;
	}
	return (only_numbers);
}
