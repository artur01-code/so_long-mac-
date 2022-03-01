/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:06:05 by jtomala           #+#    #+#             */
/*   Updated: 2022/03/01 11:07:18 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
creates the actual map by putting the image to the window
*/
void fill_map(t_mlx mlx, int x, int y, char *line)
{
	while (x < mlx.map.columns && line != NULL)
	{
		if (line[x] == '0')
		{
			mlx.img.img = mlx_xpm_file_to_image(mlx.mlx, "./img/ground.xpm", &mlx.img.width, &mlx.img.heigth);
			mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img.img, x * 99, y * 99);
		}
		if (line[x] == '1')
		{
			mlx.img.img = mlx_xpm_file_to_image(mlx.mlx, "./img/wall.xpm", &mlx.img.width, &mlx.img.heigth);
			mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img.img, x * 99, y * 99);
		}
		if (line[x] == 'C')
		{
			mlx.img.img = mlx_xpm_file_to_image(mlx.mlx, "./img/rice.xpm", &mlx.img.width, &mlx.img.heigth);
			mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img.img, x * 99, y * 99);
		}
		if (line[x] == 'E')
		{
			mlx.img.img = mlx_xpm_file_to_image(mlx.mlx, "./img/tombstone.xpm", &mlx.img.width, &mlx.img.heigth);
			mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img.img, x * 99, y * 99);
		}
		if (line[x] == 'P')
		{
			mlx.img.img = mlx_xpm_file_to_image(mlx.mlx, "./img/player.xpm", &mlx.img.width, &mlx.img.heigth);
			mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img.img, x * 99, y * 99);
			mlx.player->x = x;
			mlx.player->y = y;
		}
		if (line[x] == '\n' || !line[x])
			mlx.map.map[y] = strdup(line); //libft | not sure if it works (?)
		x++;
	}
}

/*
fills the **map with the variables with the fill_map-function
*/
int create_map(t_mlx mlx)
{
	int		x;
	int		y;
	int		fd;
	char	*line;

	x = 0;
	y = 0;
	mlx.img.img = mlx_new_image(mlx.mlx, 1300, 500);
	if (malloc_map(mlx.map) == 0)
		return (0);
	fd = open("maps/map1.ber", O_RDONLY);
	while (y < mlx.map.rows)
	{
		line = get_next_line(fd);
		fill_map(mlx, x, y, line);
		free(line);
		x = 0;
		y++;
	}
	close(fd);
	return (1);
}

/*
mallocs the map based on the rows x columns
*/
int malloc_map(t_map map)
{
	int i;

	i = 0;
	if (map.columns == 0)
	return (0);
	map.map = malloc(map.rows * sizeof(char *));
	while (i < map.rows)
	{
		map.map[i] = malloc(map.columns * sizeof(char *));
		i++;
	}
	return (1);
}

/*
handles all the stuff that has to do with the file like reading and checking
*/
int file_handler(t_mlx mlx)
{
	int fd;
	char *line;
	
	mlx.map.rows = 0;
	mlx.map.columns = 0;
	fd = open("./maps/map1.ber", O_RDONLY);
	line = get_next_line(fd);
	printf("before while)");
	while (line != NULL)
	{
		while (line[mlx.map.columns] != '\n' && line[mlx.map.columns] != '\0')
			mlx.map.columns += 1;
		free(line);
		mlx.map.rows += 1;
		line = get_next_line(fd);
		if (line != NULL)
			mlx.map.columns = 0;
	}
	close(fd);
	free(line);
	if (create_map(mlx) == 0)
		return (0);
	return (1);
}