/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:40:36 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/07 17:23:50 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_raw_map raw_map;
	t_map_data map_data;

	/* parsing */
	read_and_save(&raw_map, argv[1]);
	is_valid_map(&raw_map);
	put_map_data(&raw_map, &map_data);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			printf("%d ", map_data.point[i][j].z);
	}
}
