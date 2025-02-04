/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_7_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:21:36 by akajjou           #+#    #+#             */
/*   Updated: 2025/01/31 19:34:41 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

bool	write_map(char ***maps, char *FileName)
{
	char	*str1;
	int		fd;
	char	*str2;
	char	*tmp;

	str2 = 0;
	fd = open(FileName, O_RDWR);
	str1 = get_next_line(fd);
	if (fd == -1 && str1 == NULL)
	{
		ft_putstr_fd("Error\nFatal Error While Reading The File\n", 2);
		return (false);
	}
	while (str1)
	{
		tmp = ft_strjoin(str2, str1);
		str2 = tmp;
		str1 = get_next_line(fd);
	}
	close(fd);
	*maps = ft_split(str2, '\n');
	return (true);
}

void	skipper(char *line, int *c_index, int *end_index)
{
	int	index;

	*c_index = 0;
	*end_index = 0;
	index = 0;
	if (!line)
		return ;
	while (line[index] && (line[index] == ' ' || line[index] == '\t'))
	{
		(*c_index)++;
		index++;
	}
	while (line[index] && ft_isprint(line[index]) && line[index] != ' '
		&& line[index] != '\t')
		index++;
	(*end_index) = index;
}

bool	null_checker(t_data *data)
{
	if (data->no == NULL || data->ea == NULL || data->we == NULL
		|| data->so == NULL)
		return (false);
	return (true);
}

bool	id_type_parse(t_data *data)
{
	int	c_index;
	int	end_index;

	if (null_checker(data) == false)
		return (false);
	skipper(data->no, &c_index, &end_index);
	if (ft_strncmp(data->no, "NO", end_index) != 0)
		return (false);
	skipper(data->ea, &c_index, &end_index);
	if (ft_strncmp(data->ea, "EA", end_index) != 0)
		return (false);
	skipper(data->we, &c_index, &end_index);
	if (ft_strncmp(data->we, "WE", end_index) != 0)
		return (false);
	skipper(data->so, &c_index, &end_index);
	if (ft_strncmp(data->so, "SO", end_index) != 0)
		return (false);
	return (true);
}

int	ft_arg_count(char **texture)
{
	int	count;

	if (!texture)
		return (0);
	count = 0;
	while (texture[count])
		count++;
	return (count);
}
