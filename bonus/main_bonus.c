/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:23:38 by nait-bou          #+#    #+#             */
/*   Updated: 2025/01/30 19:45:52 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

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
