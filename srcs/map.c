/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukkan <tlaukkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:21:37 by tlaukkan          #+#    #+#             */
/*   Updated: 2020/01/17 15:50:39 by tlaukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		map_size(int nb)
{
	int i;

	i = 2;
	while (i * i < nb)
		i++;
	return (i);
}

char	**create_map(t_tetr *tetris, int size)
{
	char	**map;
	int		i;

	i = 0;
	tetris->size = size;
	if (!(map = (char **)malloc(sizeof(char *) * size + 1)))
		return (0);
	while (i < size)
	{
		if (!(map[i] = ft_strnew(size)))
			return (0);
		ft_memset(map[i], '.', size);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	map_printer(char **map)
{
	int i;

	i = 0;
	while (map[i])
		ft_putendl(map[i++]);
}

void	clean(char **map)
{
	int i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		ft_strdel(&map[i]);
		i++;
	}
	free(map);
}
