/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:01:01 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/07 02:28:30 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

t_bool	read_and_save(t_raw_map *raw_map, char *argv)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		raw_map->map_str[i++] = ft_split(line, '\t');
		line = get_next_line(fd);
	}
	raw_map->map_str[i] = 'NULL';
	raw_map->row_len = i;
}

static t_bool	split_and_put(t_raw_map *raw_map, t_map_data *map_data, size_t row_len, size_t col_len)
{
	size_t	i;
	size_t	j;
	char	**temp;

	i = 0;
	while (i < row_len)
	{
		j = 0;
		while (j < col_len)
		{
			temp = ft_split(raw_map->map_str[i][j], ',');
			map_data->point[i][j].z = ft_atoi(temp[0]);
			if (temp[1])
				map_data->point[i][j].color = ft_htoi(temp[1]);
			else
				map_data->point[i][j].color = 0;
			j++;
		}
		i++;
	}
}

t_bool	put_map_data(t_raw_map *raw_map, t_map_data *map_data)
{
	size_t	row_len_cp;
	size_t	col_len_cp;
	size_t	i;
	size_t	j;

	row_len_cp = raw_map->row_len;
	col_len_cp = raw_map->col_len;
	map_data->row_len = row_len_cp;
	map_data->col_len = col_len_cp;
	i = 0;
	while (i < row_len_cp)
	{
		map_data->point[i] = (t_point *)malloc(sizeof(t_point *))
		j = 0;
		while (j < col_len_cp)
			map_data->point[i][j++] = (t_point)malloc(sizeof(t_point));
		i++;
	}
	split_and_put(raw_map, map_data, row_len_cp, col_len_cp);
}
