/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:21:20 by jtomala           #+#    #+#             */
/*   Updated: 2022/03/03 12:04:00 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*counts and displays the moves*/
void	manage_moves(t_mlx *mlx)
{
	char	*str;

	str = ft_itoa(mlx->player->counter);
	ft_printf("moves: %d\n", mlx->player->counter);
	mlx->img->img = mlx_xpm_file_to_image(mlx->mlx, "./img/wall.xpm",
			&mlx->img->width, &mlx->img->heigth);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img->img,
		0, 0);
	mlx_string_put(mlx->mlx, mlx->mlx_win, 15, 25,
		0xff00, str);
}

/*
playces a ground on the current position of the player and places 
the player on the new position (moved)
*/
void	move(t_mlx *mlx, int x, int y)
{
	if (mlx->map->map[y][x] != '1')
	{
		if (mlx->map->map[y][x] == 'C')
			mlx->player->collactables += 1;
		if (mlx->map->map[y][x] == 'E')
		{
			if (mlx->player->collactables == mlx->map->collactables)
				exit(0);
			else
				return ;
		}
		mlx->player->counter += 1;
		manage_moves(mlx);
		mlx->img->img = mlx_xpm_file_to_image(mlx->mlx, "./img/ground.xpm",
				&mlx->img->width, &mlx->img->heigth);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img->img,
			mlx->player->x * 99, mlx->player->y * 99);
		mlx->player->x = x;
		mlx->player->y = y;
		mlx->img->img = mlx_xpm_file_to_image(mlx->mlx, "./img/player.xpm",
				&mlx->img->width, &mlx->img->heigth);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img->img,
			x * 99, y * 99);
	}
}

int	ft_exit_game_cross(t_mlx *mlx)
{
	free(mlx);
	free(mlx->img);
	free(mlx->player);
	exit(0);
	return (0);
}

/*
handles all kind of keyboard-action
*/
int	key_hook(int keycode, t_mlx *mlx)
{
	int	x;
	int	y;

	x = mlx->player->x;
	y = mlx->player->y;
	if (keycode == 13)
		move(mlx, x, y - 1);
	if (keycode == 0)
		move(mlx, x - 1, y);
	if (keycode == 1)
		move(mlx, x, y + 1);
	if (keycode == 2)
		move(mlx, x + 1, y);
	else if (keycode == 53)
		exit_window(mlx, NULL);
	return (0);
}
