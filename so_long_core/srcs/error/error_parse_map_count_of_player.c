/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parse_map_count_of_player.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 23:47:36 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/20 18:07:50 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	error_parse_map_count_of_player(long count_of_player)
{
	ft_putstr("\x1B[31m");
	ft_putstr("ERROR\nThe number of players present on the map is ");
	if (count_of_player < 0)
		ft_putstr("less ");
	else
		ft_putstr("greater ");
	ft_putendl("than 1.");
	ft_putnbr(count_of_player);
	ft_putendl(" player(s) detected.");
	ft_putendl("while only 1 player can be present on the map (flag P).");
	ft_putstr("\x1B[0m");
	return (-1);
}
