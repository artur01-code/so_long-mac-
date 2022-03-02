/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:25:53 by jtomala           #+#    #+#             */
/*   Updated: 2022/03/01 15:57:54 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"




/*
handles the all the functions and manages the variables
*/
int main(int argc, char **argv)
{
	t_mlx *mlx;
	
	if (argc != 2)
	{
		printf("TWO AGRUMENTS!!! 🤦\n");
		exit(0);
	}
	else
	{
		mlx = (t_mlx *) malloc(sizeof(t_mlx));
		mlx->img = (t_img *) malloc(sizeof(t_img));
		mlx->map = (t_map *) malloc(sizeof(t_map));
		mlx->player = (t_player *) malloc(sizeof(t_player));

		mlx->map->path = argv[1];
		check_file(mlx);
		mlx->mlx = mlx_init();
		mlx->mlx_win = mlx_new_window(mlx->mlx, 1300, 500, "so_long"); //size the window depending on the map
		mlx_key_hook(mlx->mlx_win, key_hook, &mlx->mlx);
		file_handler(mlx);
		mlx_loop(mlx->mlx);

		free(mlx);
		free(mlx->img);
		free(mlx->map);
		free(mlx->player);
	}
	return (0);
}