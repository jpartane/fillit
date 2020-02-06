/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukkan <tlaukkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:26:35 by tlaukkan          #+#    #+#             */
/*   Updated: 2020/01/20 12:09:49 by tlaukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Checks if the hash's edges connects to eachother in the grid
*/

static int	check_connect(char *block, int i)
{
	int	connect;

	connect = 0;
	if ((block[i + 1] == '#') && i <= 16)
		connect++;
	if ((block[i - 1] == '#') && i >= 1)
		connect++;
	if ((block[i - 4] == '#') && i >= 4)
		connect++;
	if ((block[i + 4] == '#') && i <= 12)
		connect++;
	return (connect);
}

static int	check_valid(char *file, int dots, int hash)
{
	int connect;
	int	i;

	i = 0;
	connect = 0;
	while (file[i] && i < 17)
	{
		if (file[i] == '.')
			dots++;
		if (file[i] == '#')
		{
			connect = connect + check_connect(file, i);
			hash++;
		}
		i++;
	}
	if (dots == 12 && hash == 4 && (connect == 6 || connect == 8))
		return (1);
	return (0);
}

/*
**	separates each block and checks if they're valid.
**	note: function skips newlines so the shape is easier to identify later.
*/

int			save_blocks(t_tetr *tetris, int x)
{
	int i;
	int l;

	i = 0;
	if (!(tetris->block = (char **)malloc(sizeof(char *) * (tetris->bc + 1))))
		return (0);
	while (tetris->file[i] && x < tetris->bc)
	{
		l = 0;
		if (!(tetris->block[x] = (char *)malloc(sizeof(char) * 16 + 1)))
			return (0);
		while (l < 17)
		{
			if (tetris->file[i] == '\n')
				i++;
			tetris->block[x][l++] = tetris->file[i++];
		}
		tetris->block[x][l] = '\0';
		if (!(check_valid(tetris->block[x], 0, 0)))
			return (0);
		x++;
	}
	tetris->block[x] = NULL;
	return (1);
}

int			validate(t_tetr *tetris)
{
	if (!(save_blocks(tetris, 0)))
		return (0);
	return (1);
}
