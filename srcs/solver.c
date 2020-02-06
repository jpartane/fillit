/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukkan <tlaukkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:19:13 by tlaukkan          #+#    #+#             */
/*   Updated: 2020/01/20 11:47:34 by jpartane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** removes the block from the map.
*/

void	remove_block(t_tetr *tetris, char *block, int x, int y)
{
	int i;
	int	reset_x;

	i = 0;
	reset_x = x;
	while (block[i])
	{
		if (block[i] == '\n')
		{
			x = reset_x;
			y++;
		}
		else
		{
			if (block[i] != '.')
				tetris->map[y][x] = '.';
			x++;
		}
		i++;
	}
}

/*
** to the given spot (x, y) it places the block.
*/

void	insert_block(t_tetr *tetris, char *block, int x, int y)
{
	int i;
	int	reset_x;

	i = 0;
	reset_x = x;
	while (block[i])
	{
		if (block[i] == '\n')
		{
			x = reset_x;
			y++;
		}
		else
		{
			if (block[i] != '.')
				tetris->map[y][x] = block[i];
			x++;
		}
		i++;
	}
}

/*
** This function finds a spot for the block and checks if it fits or not.
** (note that reset_x, resets the x to the original spot when
** the function was called because of /n.)
*/

int		find_block(t_tetr *tetris, char *block, int x, int y)
{
	int i;
	int	reset_x;

	i = 0;
	reset_x = x;
	while (block[i])
	{
		if (block[i] == '\n')
		{
			x = reset_x;
			y++;
		}
		else
		{
			if (x >= tetris->size || y >= tetris->size)
				return (0);
			if (block[i] != '.' && tetris->map[y][x] != '.')
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}

/*
** x and y needs to be smaller than tetris->size so it acts as a
** (border) and the program doesnt go over the map
** First it checks if the piece fits or not.
** after this it places the piece in to the map
** then it checks if there are pieces left OR is it capable to put
** the next piece in the map.
** If the next piece couldnt be inserted, it will remove
** the earlier piece and move the piece to the right by one (x + 1)
** If the next piece is eligible to be inserted, then it will
** increase index value by 1 (move to the next piece)
** and repeat this whole process.
*/

int		place_it(t_tetr *tetris, char **block, int index)
{
	int x;
	int y;

	y = 0;
	while (y < tetris->size)
	{
		x = 0;
		while (x < tetris->size)
		{
			if (find_block(tetris, block[index], x, y))
			{
				insert_block(tetris, block[index], x, y);
				if (index == (tetris->bc - 1) ||
							place_it(tetris, block, index + 1))
					return (1);
				else
				{
					remove_block(tetris, block[index], x, y);
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	solver(t_tetr *tetris, int size)
{
	tetris->map = create_map(tetris, size);
	tetris->size = size;
	if (!(place_it(tetris, tetris->shapes, 0)))
	{
		clean(tetris->map);
		solver(tetris, tetris->size + 1);
	}
	else
	{
		map_printer(tetris->map);
		clean(tetris->map);
	}
}
