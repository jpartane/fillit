/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukkan <tlaukkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:15:48 by tlaukkan          #+#    #+#             */
/*   Updated: 2020/01/17 18:07:22 by jpartane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 546

typedef	struct	s_tetr
{
	char		**block;
	char		**shapes;
	char		*file;
	char		c;
	int			hash;
	int			bc;
	char		**map;
	int			size;
}				t_tetr;

int				identify(t_tetr *tetris);
char			*find_shape(char *block);
int				validate(t_tetr *tetris);
void			solver(t_tetr *tetris, int size);
void			map_printer(char **map);
int				map_size(int nb);
char			**create_map(t_tetr *tetris, int size);
void			clean(char **map);

#endif
