/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:25:53 by jtomala           #+#    #+#             */
/*   Updated: 2022/03/01 11:25:39 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h> //strdup

/*
moves the player one pixe up
*/
void move_up(t_mlx mlx)
{
	//DESTROY IMAGE
	
	mlx.player->y -= 1;
	
	mlx.img.img = mlx_xpm_file_to_image(mlx.mlx, "./img/player.xpm", &mlx.img.width, &mlx.img.heigth);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img.img, mlx.player->x * 99, mlx.player->y * 99);
}

/*
handles all kind of keyboard-action
*/
int key_hook(int keycode, t_mlx mlx)
{
	mlx.map.path = "test"; //REMOVE
	if (keycode == 13)
		move_up(mlx);
	if (keycode == 0)
		write(1, "A", 1);
		//move_left(t_mlx mlx);
	if (keycode == 1)
		write(1, "S", 1);
		//move_down(t_mlx mlx);
	if (keycode == 2)
		write(1, "D", 1);
		//move_right(t_mlx mlx);
	else if (keycode == 53)
		write(1, "ESC", 3);
		//exit_window(t_mlx mlx);
	return (0);
}


/*
handles the all the functions and manages the variables
*/
int main(int argc, char **argv)
{
	t_mlx mlx;
	
	if (argc != 2)
	{
		printf("TWO AGRUMENTS!!! 🤦\n");
		exit(0);
	}
	else
	{
		mlx.mlx = malloc(1 * sizeof(void *));
    	mlx.player = (t_player *)malloc(1 * sizeof(t_player));
		mlx.img.img = malloc(1 * sizeof(void *));

		mlx.map.path = argv[1];
		mlx.mlx = mlx_init();
		mlx.mlx_win = mlx_new_window(mlx.mlx, 1300, 500, "so_long"); //size the window depending on the map
		mlx_key_hook(mlx.mlx_win, key_hook, &mlx.mlx);
		file_handler(mlx);
		mlx_loop(mlx.mlx);
	
		free(mlx.mlx);
		free(mlx.player);
		free(mlx.img.img);
	}
	return (0);
}