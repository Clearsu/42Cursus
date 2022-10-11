/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:40:36 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/11 21:51:22 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_raw_map raw_map;
	t_map_data map_data;

	argc = 0;
	if (argc != 2)
		error(1);
	read_and_save(&raw_map, argv[1]);
	is_valid_map(&raw_map);
	put_map_data(&raw_map, &map_data);
	iso_projection(&map_data);
	show_image(&map_data);
	return (0);
}
