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

#include "so_long_bonus.h"

void	print_steps(t_game_data *game_info)
{
	char	*move;

	move = ft_itoa(game_info->steps);
	mlx_string_put(game_info->mlx, game_info->win, 20, 20, 0xffffff, "Steps:");
	mlx_string_put(game_info->mlx, game_info->win, 70, 20, 0xffffff, move);
	free(move);
}

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
			ft_putstr_fd("Congrats, you won in the game!", 1);
			destroy_wind(game_info);
		}
		else
			return ;
	}
	if (game_info->map[game_info->player_y - 1][game_info->player_x] == 'B')
	{
		ft_putstr_fd("You died", 1);
		destroy_wind(game_info);
	}
	game_info->player_y--;
	draw_map(game_info);
	print_steps(game_info);
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
			ft_putstr_fd("Congrats, you won in the game!", 1);
			destroy_wind(game_info);
		}
		else
			return ;
	}
	if (game_info->map[game_info->player_y + 1][game_info->player_x] == 'B')
	{
		ft_putstr_fd("You died", 1);
		destroy_wind(game_info);
	}
	game_info->player_y++;
	draw_map(game_info);
	print_steps(game_info);
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
