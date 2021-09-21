/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parse_map_side.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 23:33:56 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/20 18:17:26 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	error_parse_map_side(t_map map)
{
	ft_putstr("\x1B[31m");
	ft_putstr("ERROR\nThe line ");
	ft_putnbr(map.pos_y + 1);
	ft_putendl(" is not surrounded by a wall (flag 1).");
	ft_putstr("-> ");
	ft_putendl(map.content[map.pos_y]);
	ft_putstr("\x1B[0m");
	return (-1);
}
