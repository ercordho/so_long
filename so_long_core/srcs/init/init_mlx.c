/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:43:10 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/01 23:56:46 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	init_mlx(t_mlx	*mlx)
{
	int	x;
	int	y;

	mlx->ptr = mlx_init();
	if (mlx->ptr == (void *)0)
		return (-1);
	x = mlx->map.pos_x;
	y = mlx->map.pos_y;
	mlx->win = mlx_new_window(mlx->ptr, IMG_SIZE * x, IMG_SIZE * y, "So long");
	if (mlx->win == (void *)0)
		return (-1);
	mlx->img.ptr = mlx_new_image(mlx->ptr, IMG_SIZE * x, IMG_SIZE * y);
	if (mlx->img.ptr == (void *)0)
		return (-1);
	mlx->img.data = mlx_get_data_addr(mlx->img.ptr, \
		&mlx->img.bpp, &mlx->img.ll, &mlx->img.endian);
	if (mlx->img.data == (void *)0)
		return (-1);
	return (1);
}
