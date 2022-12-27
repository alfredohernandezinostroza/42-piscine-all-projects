/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strlcpy.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aantonio <aantonio@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/08/11 12:49:36 by aantonio		  #+#	#+#			 */
/*   Updated: 2022/08/11 12:49:36 by aantonio		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	src_length;

	src_length = 0;
	while (src[src_length])
	{
		src_length++;
	}
	if (!dest || n == 0)
		return (src_length);
	i = 0;
	while (i < (n - 1) && i < src_length)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (src_length);
}
