/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:18:20 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/20 16:15:49 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	eventhandler(t_mlx *mlx)
{
	mlx_key_hook(mlx->win, get_key_down, mlx);
	mlx_loop_hook(mlx->ptr, draw_map, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, close_windows, mlx);
	mlx_loop(mlx->ptr);
}
