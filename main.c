/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:25:53 by jtomala           #+#    #+#             */
/*   Updated: 2022/03/03 08:24:37 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(t_map *map)
{
	int i;

	i = 0;
	free(map->map);
	while (i < map->rows)
	{
		free(map->map[i]);
		i++;
	}
}

void exit_window(t_mlx *mlx, char *line)
{
	free(mlx);
	free(mlx->img);
	free(mlx->map);
	free(mlx->player);
	 if(line)
	free(line);
	exit(0);
}

/*
handles the all the functions and manages the variables
*/
int main(int argc, char **argv)
{
	t_mlx *mlx;
	
	if (argc != 2)
		exit(0);
	else
	{
		mlx = (t_mlx *) malloc(sizeof(t_mlx));
		mlx->img = (t_img *) malloc(sizeof(t_img));
		mlx->map = (t_map *) malloc(sizeof(t_map));
		mlx->player = (t_player *) malloc(sizeof(t_player));

		mlx->map->path = argv[1];
		mlx->map->player = 0;
		mlx->map->exit = 0;
		mlx->map->collactables = 0;
		mlx->player->counter = 0;
		check_file(mlx);
		mlx->mlx = mlx_init();
		mlx->mlx_win = mlx_new_window(mlx->mlx, 1300, 500, "Rice rally"); //size the window depending on the map
		mlx_key_hook(mlx->mlx_win, key_hook, &mlx->mlx);
		file_handler(mlx);
		mlx_loop(mlx->mlx);

		free_map(mlx->map);
		free(mlx);
		free(mlx->img);
		free(mlx->player);
	}
	return (0);
}