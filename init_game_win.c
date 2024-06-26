/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:16:51 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/06/01 15:16:55 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	xpm_file_to_image(t_so_long *sl)
{
	sl->imgs.p.imgs[0] = mlx_xpm_file_to_image(sl->mlx_ptr,
			"./textures/plyr.xpm", &sl->imgs.p.w, &sl->imgs.p.h);
	sl->imgs.p.imgs[1] = mlx_xpm_file_to_image(sl->mlx_ptr,
			"./textures/plyr_up.xpm", &sl->imgs.p.w, &sl->imgs.p.h);
	sl->imgs.p.imgs[2] = mlx_xpm_file_to_image(sl->mlx_ptr,
			"./textures/plyr_down.xpm", &sl->imgs.p.w, &sl->imgs.p.h);
	sl->imgs.p.imgs[3] = mlx_xpm_file_to_image(sl->mlx_ptr,
			"./textures/plyr_opo.xpm", &sl->imgs.p.w, &sl->imgs.p.h);
	sl->imgs.f.img = mlx_xpm_file_to_image(sl->mlx_ptr, sl->imgs.f.path,
			&sl->imgs.f.w, &sl->imgs.f.h);
	sl->imgs.w.img = mlx_xpm_file_to_image(sl->mlx_ptr, sl->imgs.w.path,
			&sl->imgs.w.w, &sl->imgs.w.h);
	sl->imgs.c.img = mlx_xpm_file_to_image(sl->mlx_ptr, sl->imgs.c.path,
			&sl->imgs.c.w, &sl->imgs.c.h);
	sl->imgs.ex.img = mlx_xpm_file_to_image(sl->mlx_ptr, sl->imgs.ex.path,
			&sl->imgs.ex.w, &sl->imgs.ex.h);
	sl->imgs.en.img = mlx_xpm_file_to_image(sl->mlx_ptr, sl->imgs.en.path,
			&sl->imgs.en.w, &sl->imgs.en.h);
}

void	init_game_win(t_so_long *sl)
{
	sl->mlx_ptr = mlx_init();
	if (!sl->mlx_ptr)
	{
		free_map(sl->map, 1);
		ft_printf("\033[0;31mError:\033[0m Failed to initialize mlx.\n");
		exit(EXIT_FAILURE);
	}
	sl->imgs.f.path = "./textures/nothing.xpm";
	sl->imgs.w.path = "./textures/wall.xpm";
	sl->imgs.c.path = "./textures/coin.xpm";
	sl->imgs.ex.path = "./textures/exit.xpm";
	sl->imgs.en.path = "./textures/enemy.xpm";
	xpm_file_to_image(sl);
	sl->mlx_win = mlx_new_window(sl->mlx_ptr,
			(32 * (ft_strlen(sl->map[0]) - 1)), 32 * sl->lns - 1, "PACMON");
	if (!sl->mlx_win)
	{
		mlx_destroy_display(sl->mlx_ptr);
		free(sl->mlx_ptr);
		free_map(sl->map, 1);
		ft_printf("\033[0;31mError:\033[0m Failed to create window.\n");
		exit(EXIT_FAILURE);
	}
}
