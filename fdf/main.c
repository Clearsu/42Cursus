/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:40:36 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/10 22:20:53 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_raw_map raw_map;
	t_map_data map_data;

	read_and_save(&raw_map, argv[1]);
	is_valid_map(&raw_map);
	put_map_data(&raw_map, &map_data);

	size_t	row_len = map_data.row_len;
	size_t	col_len = map_data.col_len;
	for (int i = 0; i < row_len; i++)
	{
		printf("line %d :", i + 1);
		for (int j = 0; j < col_len; j++)
			printf("%d ", map_data.point[i][j].z);
		printf("\n");
	}
}
