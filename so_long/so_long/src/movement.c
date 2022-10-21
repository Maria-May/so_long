/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:34:08 by mdaryn            #+#    #+#             */
/*   Updated: 2022/06/03 18:34:10 by mdaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moving_helper_ud(t_game_data *game_info, int flag)
{
	if (game_info->map[game_info->player_y + flag][game_info->player_x] == '0')
	{
		if (game_info->map[game_info->player_y][game_info->player_x] == 'P')
			game_info->map[game_info->player_y][game_info->player_x] = '0';
		else
			game_info->map[game_info->player_y][game_info->player_x] = 'E';
		game_info->map[game_info->player_y + flag][game_info->player_x] = 'P';
		game_info->steps++;
	}
	if (game_info->map[game_info->player_y + flag][game_info->player_x] == 'C')
	{
		game_info->map[game_info->player_y][game_info->player_x] = '0';
		game_info->map[game_info->player_y + flag][game_info->player_x] = 'P';
		game_info->collectible--;
		game_info->steps++;
	}
}

void	moving_up(t_game_data *game_info)
{
	if (game_info->map[game_info->player_y - 1][game_info->player_x] == '1')
		return ;
	moving_helper_ud(game_info, -1);
	if (game_info->map[game_info->player_y - 1][game_info->player_x] == 'E')
	{
		if (game_info->collectible == 0)
		{
			game_info->steps++;
			ft_putstr_fd("Congrats, you won in ", 1);
			ft_putnbr_fd(game_info->steps, 1);
			ft_putstr_fd("\n", 1);
			destroy_wind(game_info);
		}
		else
			return ;
	}
	game_info->player_y--;
	ft_putstr_fd("Steps:", 1);
	ft_putnbr_fd(game_info->steps, 1);
	ft_putstr_fd("\n", 1);
	draw_map(game_info);
}

void	moving_down(t_game_data *game_info)
{
	if (game_info->map[game_info->player_y + 1][game_info->player_x] == '1')
		return ;
	moving_helper_ud(game_info, 1);
	if (game_info->map[game_info->player_y + 1][game_info->player_x] == 'E')
	{
		if (game_info->collectible == 0)
		{
			game_info->steps++;
			ft_putstr_fd("Congrats, you won in ", 1);
			ft_putnbr_fd(game_info->steps, 1);
			ft_putstr_fd("\n", 1);
			destroy_wind(game_info);
		}
		else
			return ;
	}
	game_info->player_y++;
	ft_putstr_fd("Steps:", 1);
	ft_putnbr_fd(game_info->steps, 1);
	ft_putstr_fd("\n", 1);
	draw_map(game_info);
}

void	choose_movment(int keycode, t_game_data *game_info)
{
	if (keycode == 1)
		return (moving_down(game_info));
	if (keycode == 13)
		return (moving_up(game_info));
	if (keycode == 2)
		return (moving_right(game_info));
	if (keycode == 0)
		return (moving_left(game_info));
}
