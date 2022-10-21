/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:33:32 by mdaryn            #+#    #+#             */
/*   Updated: 2022/06/03 18:33:34 by mdaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game_data	game_info;

	if (argc == 2)
	{
		if (check_map(argv[1], &game_info))
			start_game(&game_info);
		else
		{
			free_map(&game_info);
			ft_putstr_fd("Invalid map\n", 2);
		}
	}
	else
	{
		ft_putstr_fd("Invalid numbers of argumets\n", 2);
	}
	return (0);
}
