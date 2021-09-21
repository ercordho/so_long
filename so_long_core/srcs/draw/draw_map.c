/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:59:29 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/21 11:03:53 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static unsigned int	get_pixel_col(t_img img, int x, int y)
{
	char	*dst;

	dst = img.data + (y * img.ll + x * (img.bpp / 8));
	return (*(unsigned int *)dst);
}

static void	draw_pixel(t_img img, int cp_x, int cp_y, t_img *mlx)
{
	char	*dst;
	int		pp_x;
	int		pp_y;

	pp_y = cp_y - 1;
	while (++pp_y < cp_y + IMG_SIZE)
	{
		pp_x = cp_x - 1;
		while (++pp_x < cp_x + IMG_SIZE)
		{
			dst = mlx->data + (pp_y * mlx->ll + pp_x * (mlx->bpp / 8));
			*(unsigned int *)dst = get_pixel_col(img, pp_x - cp_x, pp_y - cp_y);
		}
	}
}

int	draw_map(t_mlx *mlx)
{
	int	cp_x;
	int	cp_y;
	int	x;
	int	y;
	int	i;

	mlx_clear_window(mlx->ptr, mlx->win);
	cp_y = -1;
	while (mlx->map.content[++cp_y])
	{
		cp_x = -1;
		while (mlx->map.content[cp_y][++cp_x])
		{
			i = ft_ischarset(SET, mlx->map.content[cp_y][cp_x]);
			if (i == -1)
				return (-1);
			x = cp_x * IMG_SIZE;
			y = cp_y * IMG_SIZE;
			draw_pixel(mlx->sprites.img[i], x, y, &mlx->img);
		}
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	if (mlx->map.is_finish == 1)
		return (success_game_is_finish(mlx));
	return (1);
}
