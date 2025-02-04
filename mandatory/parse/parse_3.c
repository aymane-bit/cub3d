/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:18:05 by akajjou           #+#    #+#             */
/*   Updated: 2025/01/31 19:36:28 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	line_char_check(char *line)
{
	int	c_index;

	c_index = 0;
	while (line[c_index])
	{
		if (line[c_index] != '1' && line[c_index] != '0' && line[c_index] != ' '
			&& line[c_index] != 'N' && line[c_index] != 'W'
			&& line[c_index] != 'S'
			&& line[c_index] != 'E'
			&& line[c_index] != '\t')
			return (false);
		c_index++;
	}
	return (true);
}

bool	map_characters_check(char **map)
{
	int	index;

	index = 0;
	while (map[index])
	{
		if (line_char_check(map[index]) == false)
		{
			ft_putstr_fd("Error\nThe Map Is Invalid\n", 2);
			return (false);
		}
		index++;
	}
	return (true);
}

bool	all_one(char *line)
{
	int	c_index;

	c_index = 0;
	while (line[c_index])
	{
		if (line[c_index] != '1' && line[c_index] != ' '
			&& line[c_index] != '\t')
			return (false);
		c_index++;
	}
	return (true);
}

bool	border_check(char *line)
{
	int		v_index;
	char	**line_split;

	v_index = 0;
	line_split = ft_split(line, ' ');
	while (line_split[v_index])
	{
		if (line_split[v_index][0] != '1')
			return (false);
		if (line_split[v_index][ft_strlen(line_split[v_index]) - 1] != '1')
			return (false);
		v_index++;
	}
	return (true);
}

bool	map_border_check(char **map)
{
	int	v_index;

	v_index = 0;
	while (map[v_index])
	{
		if (v_index == 0 || map[v_index + 1] == NULL)
		{
			if (all_one(map[v_index]) == false)
				return (false);
		}
		else if (border_check(map[v_index]) == false)
			return (false);
		v_index++;
	}
	return (true);
}
