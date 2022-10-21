/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:34:15 by mdaryn            #+#    #+#             */
/*   Updated: 2022/06/03 18:34:16 by mdaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	moving_helper_rl(t_game_data *game_info, int flag)
{
	if (game_info->map[game_info->player_y][game_info->player_x + flag] == '0')
	{
		if (game_info->map[game_info->player_y][game_info->player_x] == 'P')
			game_info->map[game_info->player_y][game_info->player_x] = '0';
		else
			game_info->map[game_info->player_y][game_info->player_x] = 'E';
		game_info->map[game_info->player_y][game_info->player_x + flag] = 'P';
		game_info->steps++;
	}
	if (game_info->map[game_info->player_y][game_info->player_x + flag] == 'C')
	{
		game_info->map[game_info->player_y][game_info->player_x] = '0';
		game_info->map[game_info->player_y][game_info->player_x + flag] = 'P';
		game_info->collectible--;
		game_info->steps++;
	}
}

void	moving_right(t_game_data *game_info)
{
	if (game_info->map[game_info->player_y][game_info->player_x + 1] == '1')
		return ;
	moving_helper_rl(game_info, 1);
	if (game_info->map[game_info->player_y][game_info->player_x + 1] == 'E')
	{
		if (game_info->collectible == 0)
		{
			game_info->steps++;
			ft_putstr_fd("Congrats, you won in the game!", 1);
			destroy_wind(game_info);
		}
		else
			return ;
	}
	if (game_info->map[game_info->player_y][game_info->player_x + 1] == 'B')
	{
		ft_putstr_fd("You died", 1);
		destroy_wind(game_info);
	}
	game_info->player_x++;
	draw_map(game_info);
	print_steps(game_info);
}

void	moving_left(t_game_data *game_info)
{
	if (game_info->map[game_info->player_y][game_info->player_x - 1] == '1')
		return ;
	moving_helper_rl(game_info, -1);
	if (game_info->map[game_info->player_y][game_info->player_x - 1] == 'E')
	{
		if (game_info->collectible == 0)
		{
			game_info->steps++;
			ft_putstr_fd("Congrats, you won in the game", 1);
			destroy_wind(game_info);
		}
		else
			return ;
	}
	if (game_info->map[game_info->player_y][game_info->player_x - 1] == 'B')
	{
		ft_putstr_fd("You died", 1);
		destroy_wind(game_info);
	}
	game_info->player_x--;
	draw_map(game_info);
	print_steps(game_info);
}
