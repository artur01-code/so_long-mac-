/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:06:28 by jtomala           #+#    #+#             */
/*   Updated: 2022/03/01 10:58:12 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct s_player {
	int 	x;
	int		y;
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
}				t_map;

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	t_map	map;
	t_player *player;
}				t_mlx;

#include "mlx/mlx.h"
#include "get_next_line.h"
#include <string.h> //strdup | remove

int file_handler(t_mlx mlx);
int malloc_map(t_map map);
int create_map(t_mlx mlx);
void fill_map(t_mlx mlx, int i, int j, char *line);
int key_hook(int keycode, t_mlx mlx);
void move_up(t_mlx mlx);


#endif