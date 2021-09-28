/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_windows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:08:12 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/28 14:04:56 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	close_windows(t_mlx *mlx)
{
	int	i;

	if (mlx->win)
		mlx_destroy_window(mlx->ptr, mlx->win);
	i = -1;
	if (mlx->sprites.img)
	{
		while (mlx->sprites.img[++i].ptr)
			mlx_destroy_image(mlx->ptr, mlx->sprites.img[i].ptr);
	}
	if (mlx->img.ptr)
		mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	ft_memdels((void **)&mlx->map.content, (void **)mlx->map.content);
	ft_memdel((void **)&mlx->sprites.img);
	system("leaks so_long");
	if (mlx->end ==  1)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
