/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:33:45 by mdaryn            #+#    #+#             */
/*   Updated: 2022/06/03 18:33:46 by mdaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_map_info(t_map_data	*map_info)
{
	map_info->player_start = 0;
	map_info->wall = 0;
	map_info->empty_space = 0;
	map_info->collectible = 0;
	map_info->exit = 0;
	map_info->opponent = 0;
}

static int	check_filename(char *filename)
{
	char	*ext;

	if (!filename)
		return (1);
	ext = ft_strchr(filename, '.');
	if (!ft_strncmp(ext, ".ber", 5))
		return (0);
	return (1);
}

static char	**get_map(char *filename)
{
	int		fd;
	char	*map_line;
	char	*tmp;
	char	*line;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_line = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = map_line;
		map_line = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
	}
	map = ft_split(map_line, '\n');
	free(map_line);
	close(fd);
	return (map);
}

int	check_map(char *filename, t_game_data *game_info)
{
	t_map_data	map_info;

	game_info->map = get_map(filename);
	if (!game_info->map)
		return (0);
	init_map_info(&map_info);
	if (check_filename(filename) || map_valid(game_info, &map_info))
		return (0);
	return (1);
}
