/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:33:14 by mdaryn            #+#    #+#             */
/*   Updated: 2022/06/03 18:33:16 by mdaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_map_helper_one(t_game_data *game_info, int i, int j)
{
	if (game_info->map[i][j] == '1')
	{
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->empty_space_texture, j * 32, i * 32);
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->wall_texture, j * 32, i * 32);
	}
	else if (game_info->map[i][j] == '0')
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->empty_space_texture, j * 32, i * 32);
	else if (game_info->map[i][j] == 'E')
	{
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->empty_space_texture, j * 32, i * 32);
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->exit_texture, j * 32, i * 32);
	}
}

static void	draw_map_helper_two(t_game_data *game_info, int i, int j)
{
	if (game_info->map[i][j] == 'C')
	{
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->empty_space_texture, j * 32, i * 32);
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->collectible_texture, j * 32, i * 32);
	}
	else if (game_info->map[i][j] == 'P')
	{
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->empty_space_texture, j * 32, i * 32);
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->player_texture, j * 32, i * 32);
	}
}

void	draw_map(t_game_data *game_info)
{
	int	i;
	int	j;

	i = 0;
	while (game_info->map[i])
	{
		j = 0;
		while (game_info->map[i][j])
		{
			draw_map_helper_one(game_info, i, j);
			draw_map_helper_two(game_info, i, j);
			j++;
		}
		i++;
	}
}
