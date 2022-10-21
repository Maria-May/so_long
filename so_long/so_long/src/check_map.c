/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:32:03 by mdaryn            #+#    #+#             */
/*   Updated: 2022/06/03 18:32:06 by mdaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_simbols(t_game_data *game_info,
	t_map_data	*map_info, int i, int j)
{
	if (game_info->map[i][j] == '1')
		map_info->wall++;
	else if (game_info->map[i][j] == '0')
		map_info->empty_space++;
	else if (game_info->map[i][j] == 'C')
		map_info->collectible++;
	else if (game_info->map[i][j] == 'E')
		map_info->exit++;
	else if (game_info->map[i][j] == 'P')
	{
		map_info->player_start++;
		game_info->player_x = j;
		game_info->player_y = i;
	}
	else
		return (0);
	return (1);
}

static int	check_correct_char(t_game_data *game_info, t_map_data	*map_info)
{
	int	i;
	int	j;

	i = 0;
	game_info->width = ft_strlen(game_info->map[0]);
	while (game_info->map[i])
	{
		j = 0;
		while (game_info->map[i][j])
		{
			if (!check_simbols(game_info, map_info, i, j))
				return (0);
			j++;
		}
		if (ft_strlen(game_info->map[i]) != game_info->width)
			return (0);
		i++;
	}
	game_info->height = i;
	game_info->collectible = map_info->collectible;
	return (1);
}

static int	check_rect_walls(t_game_data *game_info)
{
	int	i;
	int	j;

	i = 0;
	while (game_info->map[i])
	{
		j = 0;
		while (game_info->map[i][j])
		{
			if (game_info->map[0][j] != '1' || game_info->map[i][0] != '1'
				|| game_info->map[game_info->height - 1][j] != '1'
					|| game_info->map[i][game_info->width - 1] != '1')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_info(t_map_data	*map_info)
{
	if (map_info->collectible > 0 && map_info->exit > 0
		&& map_info->player_start > 0)
		return (1);
	return (0);
}

int	map_valid(t_game_data *game_info, t_map_data	*map_info)
{
	if (!check_correct_char(game_info, map_info))
		return (1);
	if (check_rect_walls(game_info) ||!check_info(map_info))
		return (1);
	return (0);
}
