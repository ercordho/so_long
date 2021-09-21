/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:20:36 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/17 01:51:09 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	get_key_down(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_KEY)
		close_windows(mlx);
	if (keycode == W_KEY)
		move_player(mlx, mlx->move.up);
	if (keycode == D_KEY)
		move_player(mlx, mlx->move.right);
	if (keycode == S_KEY)
		move_player(mlx, mlx->move.down);
	if (keycode == A_KEY)
		move_player(mlx, mlx->move.left);
	return (keycode);
}
