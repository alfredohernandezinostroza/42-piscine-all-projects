/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strncpy.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aantonio <aantonio@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/08/11 12:49:36 by aantonio		  #+#	#+#			 */
/*   Updated: 2022/08/11 12:49:36 by aantonio		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
