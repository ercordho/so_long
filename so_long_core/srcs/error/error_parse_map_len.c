/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parse_map_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 23:08:57 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/20 18:07:50 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	error_parse_map_len(t_map map, long line_len)
{
	ft_putstr("\x1B[31m");
	ft_putstr("ERROR\nThe line ");
	ft_putnbr((long)map.pos_y + 1);
	ft_putstr(" must be the same length as the previous line is ");
	ft_putnbr((long)ft_strlen(map.content[map.pos_y - 1]));
	ft_putstr(" and not ");
	ft_putnbr(line_len);
	ft_putendl(".");
	ft_putstr("\x1B[0m");
	return (-1);
}
