/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukkan <tlaukkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:41:30 by tlaukkan          #+#    #+#             */
/*   Updated: 2020/01/16 11:19:26 by tlaukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*find_shape_two(char *block)
{
	if (ft_strstr(block, "##..##"))
		return ("##\n##");
	if (ft_strstr(block, ".##.##"))
		return (".##\n##.");
	if (ft_strstr(block, "#...##...#"))
		return ("#.\n##\n.#");
	if (ft_strstr(block, "###..#"))
		return ("###\n.#.");
	if (ft_strstr(block, ".#..##...#"))
		return (".#\n##\n.#");
	if (ft_strstr(block, ".#..###"))
		return (".#.\n###");
	if (ft_strstr(block, "#...##..#"))
		return ("#.\n##\n#.");
	if (ft_strstr(block, "##...##"))
		return ("##.\n.##");
	if (ft_strstr(block, ".#..##..#"))
		return (".#\n##\n#.");
	return (NULL);
}

char	*find_shape_one(char *block)
{
	if (ft_strstr(block, "####"))
		return ("####");
	if (ft_strstr(block, "#...#...#...#"))
		return ("#\n#\n#\n#\n");
	if (ft_strstr(block, "#...#..##"))
		return (".#\n.#\n##");
	if (ft_strstr(block, "#...###"))
		return ("#..\n###");
	if (ft_strstr(block, "##..#...#"))
		return ("##\n#.\n#.");
	if (ft_strstr(block, "###...#"))
		return ("###\n..#");
	if (ft_strstr(block, "#...#...##"))
		return ("#.\n#.\n##");
	if (ft_strstr(block, "###.#"))
		return ("###\n#..");
	if (ft_strstr(block, "##...#...#"))
		return ("##\n.#\n.#");
	if (ft_strstr(block, "..#.###"))
		return ("..#\n###");
	return (NULL);
}

char	*find_shape(char *block)
{
	if (find_shape_one(block))
		return (find_shape_one(block));
	if (find_shape_two(block))
		return (find_shape_two(block));
	return (NULL);
}
