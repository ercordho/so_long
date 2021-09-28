/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:18:38 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/28 15:02:23 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	main(int argc, char **argv)
{
	t_file	file;
	t_map	map;
	
	if (argc == 2)
	{
		if (parse_file(&file, SET, argv[1]) == -1)
		{
			ft_memdel((void **)&file.content);
//			system("leaks so_long");
			exit(EXIT_FAILURE);
		}
		if (parse_map(&map, file.content) == -1)
		{
			ft_memdel((void **)&file.content);
//			system("leaks so_long");
			exit(EXIT_FAILURE);
		}
		so_long(map);
	}
	else
		error_fee_many_arg(argc);
//	system("leaks so_long");
	exit(EXIT_FAILURE);
}
