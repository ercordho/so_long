/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 01:07:05 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/21 10:57:33 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	move_player_display(int count_of_move, t_dot player_pos)
{
	ft_putstr("Movement count = ");
	ft_putnbr((long)count_of_move);
	ft_putchar('\t');
	ft_putstr("Player position (");
	ft_putnbr((long)player_pos.x);
	ft_putchar(',');
	ft_putnbr((long)player_pos.y);
	ft_putchar(',');
	ft_putnbr((long)player_pos.z);
	ft_putendl(").");
}

static int	player_can_move_next_pos(t_map map, t_dot player_next_pos)
{
	if (map.content[player_next_pos.y][player_next_pos.x] == '1')
		return (-1);
	if (map.content[player_next_pos.y][player_next_pos.x] == 'E')
	{
		if (map.count_of_item == 0)
			return (1);
		return (-1);
	}
	return (0);
}

static void	update_map(t_mlx *mlx, t_dot player_old_pos, t_dot player_new_pos)
{
	if (mlx->map.content[player_new_pos.y][player_new_pos.x] == 'C')
		mlx->map.count_of_item--;
	mlx->map.content[player_old_pos.y][player_old_pos.x] = '0';
	mlx->map.content[player_new_pos.y][player_new_pos.x] = 'P';
}

void	move_player(t_mlx *mlx, t_dot move)
{
	t_dot		tmp_player_pos;

	tmp_player_pos = dot_add(mlx->map.player_pos, move);
	mlx->map.is_finish = player_can_move_next_pos(mlx->map, tmp_player_pos);
	if (mlx->map.count_of_move > mlx->map.walkable_surface)
		error_too_much_movement(mlx);
	else
	{
		if (mlx->map.is_finish != -1)
		{
			update_map(mlx, mlx->map.player_pos, tmp_player_pos);
			mlx->map.player_pos = tmp_player_pos;
			move_player_display(++mlx->map.count_of_move, mlx->map.player_pos);
		}
	}
}
