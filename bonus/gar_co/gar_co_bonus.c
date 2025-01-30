/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gar_co_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:43:43 by nait-bou          #+#    #+#             */
/*   Updated: 2025/01/30 19:21:00 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d_bonus.h"

t_allocation	**get_heap_garco(void)
{
	static t_allocation	*allocations = NULL;

	return (&allocations);
}

void	*ft_malloc(size_t size)
{
	void			*ptr;
	t_allocation	*new_alloc;
	t_allocation	**allocations;

	allocations = get_heap_garco();
	ptr = malloc(size);
	if (!ptr)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		exit(EXIT_FAILURE);
	}
	new_alloc = (t_allocation *)malloc(sizeof(t_allocation));
	if (!new_alloc)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		free(ptr);
		exit(EXIT_FAILURE);
	}
	new_alloc->ptr = ptr;
	new_alloc->next = *allocations;
	*allocations = new_alloc;
	return (ptr);
}

void	ft_free_all(void)
{
	t_allocation	*current;
	t_allocation	*next;
	t_allocation	**allocations;

	allocations = get_heap_garco();
	current = *allocations;
	while (current)
	{
		next = current->next;
		free(current->ptr);
		free(current);
		current = next;
	}
	*allocations = NULL;
}

t_global	**get_heap(void)
{
	static t_global	*global;

	return (&global);
}
