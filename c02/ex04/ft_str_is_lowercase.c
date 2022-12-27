/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_str_is_lowercase.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aantonio <aantonio@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/08/11 12:59:26 by aantonio		  #+#	#+#			 */
/*   Updated: 2022/08/11 12:59:26 by aantonio		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	only_letters;

	only_letters = 1;
	i = 0;
	while (str[i])
	{
		if ('a' > str[i] || str[i] > 'z')
		{
			only_letters = 0;
			break ;
		}
		i++;
	}
	return (only_letters);
}
