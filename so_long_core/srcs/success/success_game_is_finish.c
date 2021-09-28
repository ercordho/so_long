/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   success_game_is_finish.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:19:46 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/28 14:07:11 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	success_game_is_finish(t_mlx *mlx)
{
	ft_putstr("\x1B[32m");
	ft_putendl("Your mission has been successfully completed !");
	ft_putendl("You WIN :D");
	ft_putstr("\x1B[0m");
	mlx->end = 1;
	return (close_windows(mlx));
}
