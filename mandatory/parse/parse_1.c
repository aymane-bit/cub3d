/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:16:59 by akajjou           #+#    #+#             */
/*   Updated: 2025/01/31 19:36:06 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	w_h_store(t_data *data, char **map)
{
	size_t	w_map;
	int		v_index;

	v_index = 0;
	w_map = ft_strlen(map[v_index]);
	while (map[v_index])
	{
		if (w_map < ft_strlen(map[v_index]))
			w_map = ft_strlen(map[v_index]);
		v_index++;
	}
	data->h_map = ft_arg_count(map);
	data->w_map = w_map;
}

bool	map_check(t_data *data, char **map)
{
	map_writer(data, map);
	if (ft_arg_count(data->map) <= 2)
		return (ft_putstr_fd("Error\nThe Map Is Not Valid\n", 2), false);
	if (map_characters_check(data->map) == false)
		return (false);
	if (map_border_check(data->map) == false)
		return (ft_putstr_fd("Error\nThe Map Is Not Valid\n", 2), false);
	if (map_border_updown(data->map) == false)
		return (ft_putstr_fd("Error\nThe Map Is Not Valid\n", 2), false);
	if (map_valid_char(data->map) == false)
		return (ft_putstr_fd("Error\nThe Map Is Not Valid\n", 2), false);
	player_view(data, data->map);
	x_y_store(data, data->map);
	w_h_store(data, data->map);
	return (true);
}

bool	map_checker(t_data *data, char **map)
{
	if (type_id_storer(data, map) == false)
		return (false);
	if (color_storer(data, map) == false)
		return (false);
	if (map_check(data, map) == false)
		return (false);
	return (true);
}

bool	parses_map(t_global **global, t_data *data, char *FileName)
{
	char	**map;

	data = (t_data *)ft_malloc(sizeof(t_data));
	(*global)->data = data;
	ft_memset(data, 0, sizeof(t_data));
	if (write_map(&map, FileName) == false)
		return (false);
	if (map_checker(data, map) == false)
		return (false);
	return (true);
}

bool	filename_check(int argc, char **argv)
{
	int		filelen;
	char	*filename;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage : ./cub3d <map>\n", 2);
		return (false);
	}
	filelen = ft_strlen(argv[1]) - 4;
	filename = argv[1];
	if (ft_strcmp(filename + filelen, ".cub") != 0)
	{
		ft_putstr_fd("Error\nBad extension\n", 2);
		return (false);
	}
	return (true);
}
