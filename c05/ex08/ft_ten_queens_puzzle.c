/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:18:46 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/16 23:57:18 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	can_place_queen_left(int queen_col, int *rows)
{
	int	col;
	int	row_up;
	int	row_down;

	col = queen_col - 1;
	while (col >= 0)
	{
		row_up = rows[queen_col] - 1;
		row_down = rows[queen_col] + 1;
		while (row_up >= 0)
		{
			if (row_up == rows[col])
			{
				// printf("queen at col: %d, row: %d\n", col, row_up);
				return (0);
			}
			row_up --;
		}
		while (row_down < 10)
		{
			if (row_down == rows[col])
			{
				// printf("queen at col: %d, row: %d\n", col, row_down);
				return (0);
			}
			row_down ++;
		}
		col--;
	}
	return (1);
}

int	can_place_queen_right(int queen_col, int *rows)
{
	int	col;
	int	row_up;
	int	row_down;

	col = queen_col + 1;
	while (col < 10)
	{
		row_up = rows[queen_col] - 1;
		row_down = rows[queen_col] + 1;
		while (row_up >= 0)
		{
			if (row_up == rows[col])
			{
				// printf("queen at col: %d, row: %d\n", col, row_up);
				return (0);
			}
			row_up --;
		}
		while (row_down < 10)
		{
			if (row_down == rows[col])
			{
				// printf("queen at col: %d, row: %d\n", col, row_down);
				return (0);
			}
			row_down ++;
		}
		col--;
	}
	return (1);
}

int	has_equal_digits(int *rows)
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = i + 1;
		while (j < 10)
		{
			// printf("i: %d, j: %d\n", i, j);
			if (rows[i] == rows[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_if_valid(long long places)
{
	int	rows[10];
	int	col;
	int	div;

	places = places % 10000000000;
	div = 1000000000;
	col = 0;
	while (col < 10)
	{
		rows[col] = places / div;
		// printf("col: %d, row: %lld\n", col, places / div);
		places = places % div;
		div = div / 10;
		col++;
	}
	if (has_equal_digits(rows))
		return (0);
	while (col >= 0)
	{
		if (!can_place_queen_left(col, rows))
		{
			printf("can't place queen");
			return (0);
		}
		if (!can_place_queen_right(col, rows))
		{
			printf("can't place queen");
			return (0);
		}
		col--;
	}
	return (1);
}

int	ft_ten_queens_puzzle(void)
{
	long long	places;

	places = 10257948136;
	printf("%lld\n", places % 10000000000);
	while (places <= 19742051863)
	{
		if (check_if_valid(places))
			printf("%lld\n", places % 10000000000);
		places++;
	}
	return (0);
}

// int	ft_ten_queens_puzzle(void)
// {
// 	int	row;
// 	int	col;
// 	int places[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// 	col = 0;
// 	row = 0;
// 	while (col < 10){
// 		while (!can_place_queen(col, row))
// 			row++;
// 		place_queen(col, row);
// 		col++;
// 	}
// 	print_solution(places);
// 	col--;
// 	while (col >= 0)
// 	{
// 		row = places[col];
// 		while (row < 9)
// 		{
// 			if (can_place_queen(col, row))
// 			{
// 				place_queen(col, row);
// 				print_solution(places);
// 				col--;
// 			}

// 		}
// 		col--;
// 	}
// }
