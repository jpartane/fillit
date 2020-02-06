/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukkan <tlaukkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 14:46:52 by tlaukkan          #+#    #+#             */
/*   Updated: 2020/01/20 12:12:25 by tlaukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	give_letter(char *block, int letter)
{
	int i;

	i = 0;
	while (block[i])
	{
		if (block[i] == '#')
			block[i] = letter;
		i++;
	}
}

/*
**	identifies the shape of the block and gives it a letter.
**	saves each shape into the struct.
*/

int		identify(t_tetr *tetris)
{
	int i;

	i = 0;
	tetris->c = 'A';
	if (!(tetris->shapes = (char **)malloc(sizeof(char *) * tetris->bc + 1)))
		return (0);
	while (i < tetris->bc)
	{
		tetris->shapes[i] = ft_strdup(find_shape(tetris->block[i]));
		give_letter(tetris->shapes[i], tetris->c++);
		i++;
	}
	tetris->shapes[i] = NULL;
	return (1);
}
