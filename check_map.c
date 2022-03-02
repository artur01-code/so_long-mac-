/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:57:20 by jtomala           #+#    #+#             */
/*   Updated: 2022/03/02 12:28:54 by jtomala          ###   ########.fr       */
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
		printf("%d & %d", nr1, nr2);
		exit_window(mlx, line); //memory leaks
	}
}


int check_objects(t_mlx *mlx)
{
	if ((!mlx->map->player) >= 1 || (!mlx->map->exit) >= 1 || (!mlx->map->collactables) >= 1)
	{
		printf("Map error: you need at least 1xP, 1xE & 1xC");
		exit(0);
	}
	return (1);
}

/*
int check_rectangle(t_mlx *mlx, int d)
{

	if (d)
		if (!(d == mlx->map->columns))
			return (0);
	d = mlx->map->columns;
	return (1);
}*/