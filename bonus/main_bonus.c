/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:23:38 by nait-bou          #+#    #+#             */
/*   Updated: 2025/01/31 19:34:05 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

char	*ft_no_tab(char *str)
{
	int		i;
	int		j;
	char	*result;

	if (!str)
		return (NULL);
	result = (char *)ft_malloc(sizeof(char) * (strlen(str) + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			result[j++] = ' ';
		else
			result[j++] = str[i];
		i++;
	}
	result[j] = '\0';
	return (result);
}

int	main(int ac, char **av)
{
	t_global	*global;

	*get_heap_garco() = NULL;
	*get_heap() = NULL;
	if (filename_check(ac, av) == false)
		return (2);
	global = (t_global *)ft_malloc(sizeof(t_global));
	ft_memset(global, 0, sizeof(t_global));
	global->gar_co = NULL;
	*get_heap() = global;
	if (parses_map(&global, global->data, av[1]) == false)
		return (ft_free_all(), 2);
	cub3d();
	return (0);
}
