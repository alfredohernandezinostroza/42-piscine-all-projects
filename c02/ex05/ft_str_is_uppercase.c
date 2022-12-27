/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_str_is_uppercase.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aantonio <aantonio@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/08/11 12:59:26 by aantonio		  #+#	#+#			 */
/*   Updated: 2022/08/11 12:59:26 by aantonio		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	only_letters;

	only_letters = 1;
	i = 0;
	while (str[i])
	{
		if ('A' > str[i] || str[i] > 'Z')
		{
			only_letters = 0;
			break ;
		}
		i++;
	}
	return (only_letters);
}
