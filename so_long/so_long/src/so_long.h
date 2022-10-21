/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:35:51 by mdaryn            #+#    #+#             */
/*   Updated: 2022/06/03 18:35:54 by mdaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx_opengl_20191021/mlx.h"
# include "../libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>

typedef struct s_map_data
{
	int	player_start;
	int	wall;
	int	collectible;
	int	exit;
	int	empty_space;
}	t_map_data;

typedef struct s_game_data
{
	int		collectible;
	int		steps;
	char	**map;
	void	*wall_texture;
	void	*collectible_texture;
	void	*exit_texture;
	void	*player_texture;
	void	*empty_space_texture;
	int		game_over;
	int		player_x;
	int		player_y;
	void	*mlx;
	void	*win;
	int		img_h;
	int		img_w;
	int		height;
	int		width;
}	t_game_data;

int		check_map(char *filename, t_game_data *game_info);
int		map_valid(t_game_data *game_info, t_map_data	*map_info);
void	start_game(t_game_data *game_info);
void	draw_map(t_game_data *game_info);
void	choose_movment(int keycode, t_game_data *game_info);
void	free_map(t_game_data *game_info);
void	moving_right(t_game_data *game_info);
void	moving_left(t_game_data *game_info);
int		destroy_wind(t_game_data *game_info);
#endif
