/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:35:39 by mdaryn            #+#    #+#             */
/*   Updated: 2022/06/06 15:35:43 by mdaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_enemy_helper(t_game_data	*game_info,
	int counter, int i, int j)
{
	if (counter == 3)
	{
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->empty_space_texture, j * 32, i * 32);
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->opponent_texture2, j * 32, i * 32);
	}
	if (counter == 2)
	{
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->empty_space_texture, j * 32, i * 32);
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->opponent_texture1, j * 32, i * 32);
	}
	if (counter == 1)
	{
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->empty_space_texture, j * 32, i * 32);
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->opponent_texture3, j * 32, i * 32);
	}
}

static void	draw_enemy(t_game_data	*game_info, int counter)
{
	int	i;
	int	j;

	i = 0;
	while (game_info->map[i])
	{
		j = 0;
		while (game_info->map[i][j])
		{
			if (game_info->map[i][j] == 'B')
				draw_enemy_helper(game_info, counter, i, j);
			j++;
		}
		i++;
	}
}

int	time_animation(void)
{
	static int	counter;
	static int	time;

	time++;
	if (time == 10)
	{
		counter++;
		time = 0;
		if (counter > 2)
			counter = 0;
	}
	return (counter);
}

static int	enemy_animation(t_game_data *game_info)
{
	static int	counter;

	counter = time_animation();
	if (counter > 2)
		counter = 0;
	if (counter > 0)
		draw_enemy(game_info, counter);
	return (0);
}

void	animation(t_game_data *game_info)
{
	if (game_info->opponent > 0)
	{
		game_info->opponent_texture1 = mlx_xpm_file_to_image(game_info->mlx,
				"./textures/enemy1.xpm", &game_info->img_h, &game_info->img_w);
		game_info->opponent_texture2 = mlx_xpm_file_to_image(game_info->mlx,
				"./textures/enemy2.xpm", &game_info->img_h, &game_info->img_w);
		game_info->opponent_texture3 = mlx_xpm_file_to_image(game_info->mlx,
				"./textures/enemy3.xpm", &game_info->img_h, &game_info->img_w);
		draw_enemy(game_info, 1);
		mlx_loop_hook(game_info->mlx, &enemy_animation, game_info);
	}
}
