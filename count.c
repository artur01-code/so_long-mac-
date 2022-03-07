/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:01:52 by jtomala           #+#    #+#             */
/*   Updated: 2022/03/07 10:36:00 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_columns_and_rows(t_mlx *mlx)
{
	int			fd;
	char		*line;

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
		if (line != NULL)
			mlx->map->columns = 0;
	}
}
