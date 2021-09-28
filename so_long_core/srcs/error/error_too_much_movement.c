/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_too_much_movement.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:07:07 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/28 14:09:15 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	error_too_much_movement(t_mlx *mlx)
{
	ft_putstr("\x1B[31m");
	ft_putendl("ERROR");
	ft_putstr("the maximum number of movements has been reached without ");
	ft_putendl("the player having managed to exit the map.");
	ft_putstr("Max number of movements : ");
	ft_putnbr((long)mlx->map.walkable_surface);
	ft_putendl(".");
	ft_putstr("Item to collect remaining: ");
	ft_putnbr((long)mlx->map.count_of_item);
	ft_putendl(".");
	ft_putendl("You lose :(");
	ft_putstr("\x1B[0m");
	mlx->end = -1;
	close_windows(mlx);
}
