/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:02:14 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/28 14:05:59 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	clean_memory(t_mlx *mlx, int val)
{
	mlx->end = val;
	close_windows(mlx);
	return (val);
}

int	so_long(t_map map)
{
	t_mlx	mlx;

	init_move(&mlx.move);
	mlx.map = map;
	if (init_mlx(&mlx) == -1)
		return (clean_memory(&mlx, -1));
	if (init_sprites(&mlx.sprites, mlx.ptr, -1) == -1)
		return (clean_memory(&mlx, -1));
	eventhandler(&mlx);
	return (clean_memory(&mlx, 1));
}
