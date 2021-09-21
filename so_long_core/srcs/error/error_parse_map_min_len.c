/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parse_map_min_len.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 23:15:43 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/20 18:07:50 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	error_parse_map_min_len(long line_pos, long line_len)
{
	ft_putstr("\x1B[31m");
	ft_putstr("ERROR\nThe line ");
	ft_putnbr(line_pos);
	ft_putendl(" must have a minimum length of 3.");
	ft_putstr("Current len ");
	ft_putnbr(line_len);
	ft_putstr(".");
	ft_putstr("\x1B[0m");
	return (-1);
}
