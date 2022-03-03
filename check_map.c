/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:57:20 by jtomala           #+#    #+#             */
/*   Updated: 2022/03/03 07:50:39 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
checks the file if everything is valid
*/
void check_file(t_mlx *mlx)
{
	int	len;
	int	e;

	e = 0;
	len = ft_strlen(mlx->map->path);
	if (mlx->map->path[len - 1] != 'r')
		e = 1;
	if (mlx->map->path[len - 2] != 'e')
		e = 1;
	if (mlx->map->path[len - 3] != 'b')
		e = 1;
	if (mlx->map->path[len - 4] != '.')
		e = 1;
	if (e == 1)
	{
		printf("Filename not valid\n"); //include printf
		exit_window(mlx, NULL);
	}
}

void check_map(t_mlx *mlx, int nr1, int nr2, char *line)
{
	if (nr1 != nr2 && nr1 != 1)
	{
		printf("Map error: it's not ractangle.");
		exit_window(mlx, line); //memory leaks
	}
}


int check_objects(t_mlx *mlx)
{
	if ((!mlx->map->player) >= 1 || (!mlx->map->exit) >= 1 || (!mlx->map->collactables) >= 1)
	{
		printf("Map error: you need at least 1xP, 1xE & 1xC.");
		exit(0);
	}
	return (1);
}

int check_sorrounded_by_one(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(y < mlx->map->rows)
	{
		x = 0;
		while(x < mlx->map->columns)
		{
			if (mlx->map->map[0][x] != '1' || mlx->map->map[mlx->map->rows - 1][x] != '1')
			{
				printf("Map error: have to be sorroundet by 1s.");
				exit(0);
			}
			if (mlx->map->map[y][0] != '1' || mlx->map->map[y][mlx->map->columns - 1] != '1')
			{
				printf("Map error: have to be sorroundet by 1s.");
				exit(0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
