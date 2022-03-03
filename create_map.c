/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:06:05 by jtomala           #+#    #+#             */
/*   Updated: 2022/03/03 11:19:50 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_picture(t_mlx *mlx, int x, int y, char *path)
{
	mlx->img->img = mlx_xpm_file_to_image(mlx->mlx, path,
			&mlx->img->width, &mlx->img->heigth);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
		mlx->img->img, x * 99, y * 99);
}

void	set_x_y(t_mlx *mlx, int x, int y)
{
	mlx->player->x = x;
	mlx->player->y = y;
}

/*
creates the actual map by putting the image to the window
*/
void	fill_map(t_mlx *mlx, int x, int y, char *line)
{
	while (x <= mlx->map->columns && line != NULL)
	{
		if (line[x] == '0')
			place_picture(mlx, x, y, "./img/ground.xpm");
		if (line[x] == '1')
			place_picture(mlx, x, y, "./img/wall.xpm");
		if (line[x] == 'C')
		{
			mlx->map->collactables += 1;
			place_picture(mlx, x, y, "./img/rice.xpm");
		}
		if (line[x] == 'E')
		{
			mlx->map->exit += 1;
			place_picture(mlx, x, y, "./img/tombstone.xpm");
		}
		if (line[x] == 'P')
		{
			place_picture(mlx, x, y, "./img/player.xpm");
			set_x_y(mlx, x, y);
		}
		if (line[x] == '\n' || !line[x])
			mlx->map->map[y] = ft_strdup(line);
		x++;
	}
}

/*
fills the **map with the variables with the fill_map-function
*/
int	create_map(t_mlx *mlx)
{
	int		x;
	int		y;
	int		fd;
	char	*line;

	x = 0;
	y = 0;
	if (malloc_map(mlx->map) == 0)
		return (0);
	fd = open(mlx->map->path, O_RDONLY);
	while (y < mlx->map->rows)
	{
		line = get_next_line(fd);
		fill_map(mlx, x, y, line);
		free(line);
		x = 0;
		y++;
	}
	close(fd);
	if (check_objects(mlx) == 0)
		return (0);
	return (1);
}

/*
handles all the stuff that has to do with the file like reading and checking
*/
int	file_handler(t_mlx *mlx)
{
	int		fd;
	char	*line;
	int		d;

	fd = open(mlx->map->path, O_RDONLY);
	if (fd < 0)
		exit_window(mlx, NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		count_columns(mlx, line);
		free(line);
		mlx->map->rows += 1;
		line = get_next_line(fd);
		check_map(mlx, d, mlx->map->columns, line);
		d = mlx->map->columns;
		if (line != NULL)
			mlx->map->columns = 0;
	}
	free(line);
	if (create_map(mlx) == 0)
		return (0);
	if (check_sorrounded_by_one(mlx) == 0)
		return (0);
	return (1);
}
