/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:51:26 by jtomala           #+#    #+#             */
/*   Updated: 2022/03/03 11:25:45 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_columns(t_mlx *mlx, char *line)
{
	while (line[mlx->map->columns] != '\n'
		&& line[mlx->map->columns] != '\0')
		mlx->map->columns += 1;
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	size;

	size = ft_strlen(s1) + 1;
	str = malloc(size);
	if (str == NULL)
		return (NULL);
	if (str)
		ft_memcpy(str, s1, size);
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < (int) n)
	{
		((char *) dst)[i] = ((char *) src)[i];
		i++;
	}
	return (dst);
}
