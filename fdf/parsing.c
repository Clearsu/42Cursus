/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:01:01 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/11 19:21:28 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	read_and_save(t_raw_map *raw_map, char *argv)
{
	int		fd;
	int		i;
	char	*line;
	char	***temp;

	fd = open(argv, O_RDONLY);
	if (fd < 0 || fd > 256)
		error(5);
	temp = (char ***)malloc(sizeof(char **) * (MAX_ROW + 1));
	line = get_next_line(fd);
	i = 0;
	while (1)
	{
		temp[i] = ft_split(line, ' ');
		if (!temp[i++])
			error(4);
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	close(fd);
	temp[i] = NULL;
	raw_map->map_str = temp;
	raw_map->row_len = i;
}

static void	split_and_put(t_raw_map *raw_map, t_map_data *map_data, size_t row_len, size_t col_len)
{
	size_t	i;
	size_t	j;
	char	**temp;
	int		width_space;
	int		height_space;

	width_space = (WIDTH - (col_len * SPACE)) / 2;
	height_space = (HEIGHT - (row_len * SPACE)) / 2;
	i = 0;
	while (i < row_len)
	{
		j = 0;
		while (j < col_len)
		{
			map_data->point[i][j].x = width_space + (j * SPACE);
			map_data->point[i][j].y = height_space + (i * SPACE);
			temp = ft_split(raw_map->map_str[i][j], ',');
			map_data->point[i][j].z = ft_atoi(temp[0]) * SPACE;
			if (temp[1])
				map_data->point[i][j].color = ft_htoi(temp[1]);
			else
				map_data->point[i][j].color = 0x00FFFFFF;
			j++;
		}
		i++;
	}
}

void	put_map_data(t_raw_map *raw_map, t_map_data *map_data)
{
	size_t	row_len_cp;
	size_t	col_len_cp;
	size_t	i;

	row_len_cp = raw_map->row_len;
	col_len_cp = raw_map->col_len;
	map_data->row_len = row_len_cp;
	map_data->col_len = col_len_cp;
	i = 0;
	map_data->point = (t_point **)malloc(sizeof(t_point *) * row_len_cp);
	while (i < row_len_cp)
		map_data->point[i++] = (t_point *)malloc(sizeof(t_point) * col_len_cp);
	split_and_put(raw_map, map_data, row_len_cp, col_len_cp);
}
