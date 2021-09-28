/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:02:14 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/28 14:24:22 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	so_long(t_map map)
{
	t_mlx	mlx;

	init_move(&mlx.move);
	mlx.map = map;
	mlx.end = init_mlx(&mlx);
	if (init_mlx(&mlx) == -1)
		close_windows(&mlx);
	mlx.end = init_sprites(&mlx.sprites, mlx.ptr, -1);
	if (mlx.end == -1)
		close_windows(&mlx);
	eventhandler(&mlx);
}
