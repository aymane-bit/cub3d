/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:54:06 by nait-bou          #+#    #+#             */
/*   Updated: 2025/01/30 23:02:33 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	play(void *info)
{
	t_global	*global;

	global = (t_global *)info;
	if (!global || !global->mlx_image)
		return (1);
	ft_memset(mlx_get_data_addr(global->mlx_image, &(int){0}, &(int){0},
			&(int){0}), 0, S_W * S_H * 4);
	cast_rays();
	draw_minimap(global);
	mouve(global, 0, 0);
	mlx_put_image_to_window(global->mlx_p, global->mlx_w, global->mlx_image, 0,
		0);
	return (0);
}

void	init_player(void)
{
	t_global	*global;
	t_player	*player;

	global = *get_heap();
	player = global->player;
	player->x_p = global->data->x_p_m * TILE_SIZE + TILE_SIZE / 2;
	player->y_p = global->data->y_p_m * TILE_SIZE + TILE_SIZE / 2;
	player->angle = global->data->angle;
	player->fov = FOV * (M_PI / 180);
}

static void	wrap_mouse_position(t_global *global, int x, int y)
{
	if (x > S_W - 20)
	{
		x = 20;
		mlx_mouse_move(global->mlx_p, global->mlx_w, x, y);
	}
	if (x < 20)
	{
		x = S_W - 20;
		mlx_mouse_move(global->mlx_p, global->mlx_w, x, y);
	}
}

int	mouse_move(int x, int y, void *info)
{
	t_global	*global;
	static int	old_x = S_W / 2;

	(void)y;
	global = (t_global *)info;
	if (x != old_x)
	{
		global->player->angle += (x - old_x) * ROTATION_MOUSE;
		old_x = x;
	}
	if (global->player->angle < 0)
		global->player->angle += 2 * M_PI;
	else if (global->player->angle > 2 * M_PI)
		global->player->angle -= 2 * M_PI;
	wrap_mouse_position(global, x, y);
	return (0);
}

void	cub3d(void)
{
	t_global	*global;

	global = *get_heap();
	global->player = (t_player *)ft_malloc(sizeof(t_player));
	global->ray = (t_ray *)ft_malloc(sizeof(t_ray));
	ft_memset(global->player, 0, sizeof(t_player));
	ft_memset(global->ray, 0, sizeof(t_ray));
	global->mlx_p = mlx_init();
	if (!global->mlx_p)
		ft_error(ERR_MLX_INIT_FAILED);
	global->mlx_w = mlx_new_window(global->mlx_p, S_W, S_H, "cub3d");
	if (!global->mlx_w)
		ft_error(ERR_MLX_INIT_FAILED);
	global->mlx_image = mlx_new_image(global->mlx_p, S_W, S_H);
	if (!global->mlx_image)
		ft_error(ERR_MLX_INIT_FAILED);
	init_player();
	load_textures(global);
	mlx_hook(global->mlx_w, 6, 1L << 6, mouse_move, global);
	mlx_hook(global->mlx_w, 2, 1L << 0, key_press, global);
	mlx_hook(global->mlx_w, 3, 1L << 1, key_release, global);
	mlx_hook(global->mlx_w, 17, 0, (void *)ft_exit, NULL);
	mlx_loop_hook(global->mlx_p, play, global);
	mlx_loop(global->mlx_p);
}
