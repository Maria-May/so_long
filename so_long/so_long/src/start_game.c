/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:34:38 by mdaryn            #+#    #+#             */
/*   Updated: 2022/06/03 18:35:38 by mdaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_wind(t_game_data *game_info)
{
	mlx_destroy_image(game_info->mlx, game_info->wall_texture);
	mlx_destroy_image(game_info->mlx, game_info->collectible_texture);
	mlx_destroy_image(game_info->mlx, game_info->empty_space_texture);
	mlx_destroy_image(game_info->mlx, game_info->exit_texture);
	mlx_destroy_image(game_info->mlx, game_info->player_texture);
	free_map(game_info);
	exit(0);
	return (0);
}

void	free_map(t_game_data *game_info)
{
	int	i;

	if (!game_info->map)
		return ;
	i = 0;
	while (game_info->map[i])
	{
		free(game_info->map[i]);
		i++;
	}
	free(game_info->map);
	game_info->map = NULL;
}

int	key_hook(int keycode, t_game_data *game_info)
{
	if (keycode == 53)
		destroy_wind(game_info);
	if (keycode == 1 || keycode == 13 || keycode == 2 || keycode == 0)
		choose_movment(keycode, game_info);
	return (0);
}

void	start_game(t_game_data *game_info)
{
	game_info->steps = 0;
	game_info->game_over = 0;
	game_info->img_h = 32;
	game_info->img_w = 32;
	game_info->mlx = mlx_init();
	game_info->win = mlx_new_window(game_info->mlx,
			(game_info->img_w * game_info->width),
			(game_info->img_h * game_info->height),
			"So_long");
	game_info->player_texture = mlx_xpm_file_to_image(game_info->mlx,
			"./textures/player.xpm", &game_info->img_h, &game_info->img_w);
	game_info->wall_texture = mlx_xpm_file_to_image(game_info->mlx,
			"./textures/wall.xpm", &game_info->img_h, &game_info->img_w);
	game_info->collectible_texture = mlx_xpm_file_to_image(game_info->mlx,
			"./textures/coin.xpm", &game_info->img_h, &game_info->img_w);
	game_info->exit_texture = mlx_xpm_file_to_image(game_info->mlx,
			"./textures/exit.xpm", &game_info->img_h, &game_info->img_w);
	game_info->empty_space_texture = mlx_xpm_file_to_image(game_info->mlx,
			"./textures/empty.xpm", &game_info->img_h, &game_info->img_w);
	draw_map(game_info);
	mlx_hook(game_info->win, 2, 1L << 0, &key_hook, game_info);
	mlx_hook(game_info->win, 17, 0, &destroy_wind, game_info);
	mlx_loop(game_info->mlx);
}
