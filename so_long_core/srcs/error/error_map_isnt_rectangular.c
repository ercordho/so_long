/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_isnt_rectangular.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:24:45 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/20 18:07:50 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	error_map_isnt_rectangular(long x, long y)
{
	ft_putstr("\x1B[31m");
	ft_putstr("ERROR\nThe map must be rectangular ");
	ft_putstr("except the format of the map here is square (");
	ft_putnbr(x);
	ft_putstr(",");
	ft_putnbr(y);
	ft_putendl(").");
	ft_putstr("\x1B[0m");
	return (-1);
}
