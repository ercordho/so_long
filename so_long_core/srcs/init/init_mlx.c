/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:43:10 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/28 14:22:11 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	init_mlx(t_mlx	*mlx)
{
	int	x;
	int	y;

	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		return (-1);
	x = mlx->map.pos_x;
	y = mlx->map.pos_y;
	mlx->win = mlx_new_window(mlx->ptr, IMG_SIZE * x, IMG_SIZE * y, "So long");
	if (mlx->win == NULL)
		return (-1);
	mlx->img.ptr = mlx_new_image(mlx->ptr, IMG_SIZE * x, IMG_SIZE * y);
	if (mlx->img.ptr == NULL)
		return (-1);
	mlx->img.data = mlx_get_data_addr(mlx->img.ptr, \
		&mlx->img.bpp, &mlx->img.ll, &mlx->img.endian);
	if (mlx->img.data == NULL)
		return (-1);
	return (1);
}
