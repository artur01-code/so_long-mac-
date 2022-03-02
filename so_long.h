/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:06:28 by jtomala           #+#    #+#             */
/*   Updated: 2022/03/01 16:06:08 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx/mlx.h"
#include "get_next_line.h"
#include <string.h> //strdup | remove
#include <stdlib.h>

typedef struct s_player {
	int 	x;
	int		y;
	int 	collactables;
	size_t	counter;
}				t_player;

typedef struct s_img {
	void	*img;
	char	*path;
	int 	width;
	int		heigth;
}				t_img;

typedef struct s_map {
	char	**map;
	char	*path;
	int		rows;
	int		columns;
	int		collactables;
}				t_map;

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
	t_map	*map;
	t_player *player;
}				t_mlx;

int file_handler(t_mlx *mlx);
int malloc_map(t_map *map);
int create_map(t_mlx *mlx);
void fill_map(t_mlx *mlx, int i, int j, char *line);
int key_hook(int keycode, t_mlx *mlx);
void move_up(t_mlx *mlx, int x, int y);
void check_file(t_mlx *mlx);
int check_rectangle(t_mlx *mlx, int d);


#endif