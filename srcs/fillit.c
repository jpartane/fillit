/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukkan <tlaukkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:08:13 by tlaukkan          #+#    #+#             */
/*   Updated: 2020/01/20 12:12:43 by tlaukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdlib.h>

/*
**	Function counts the number of the blocks and checks correct positions
**	of newlines.
*/

static char		block_counter(char *file)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (file[i])
	{
		if (file[i] == '\n' && i % 5 != (4 + count) % 5)
			return (0);
		i++;
		if (i == 20 + 21 * count)
			count++;
	}
	if (21 * count - 1 != i)
		return (0);
	return (count);
}

/*
**	Reads the file. BUZZ_SIZE is 546. Max lenght for the file is 545 characters.
**	If read returns 546 the file is too long and it returns 0.
**	Duplicates buf in to the file.
*/

static char		*file_reader(int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*file;

	ret = read(fd, buf, BUFF_SIZE);
	if (ret == 546)
		return (0);
	buf[ret] = '\0';
	if (!(file = ft_strdup(buf)))
		return (0);
	return (file);
}

static int		start_with(int fd)
{
	t_tetr	*tetris;

	if (!(tetris = (t_tetr *)malloc(sizeof(t_tetr))))
		return (0);
	if (!(tetris->file = file_reader(fd)))
		return (0);
	if (!(tetris->bc = block_counter(tetris->file)))
		return (0);
	tetris->hash = tetris->bc * 4;
	if (!(validate(tetris)))
		return (0);
	if (!(identify(tetris)))
		return (0);
	solver(tetris, map_size(tetris->hash));
	ft_strdel(&tetris->file);
	clean(tetris->block);
	clean(tetris->shapes);
	free(tetris);
	return (1);
}

int				main(int ac, char **av)
{
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (!(start_with(fd)))
		{
			ft_putendl("error");
			exit(0);
		}
		close(fd);
	}
	else
		ft_putendl("usage:	./fillit source_file");
	return (0);
}
