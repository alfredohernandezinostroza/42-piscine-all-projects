/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:44:37 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/12 13:48:27 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ft(int *);

int main(void)
{
    int value = 1;
    int *ptr;

    ptr = &value;
    ft_ft(ptr);
    printf("Value: %d", *ptr);
    return (0);
}