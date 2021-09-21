/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_is_too_small.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:32:43 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/20 18:07:50 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	error_map_is_too_small(long map_len)
{
	ft_putstr("\x1B[31m");
	ft_putstr("ERROR\nThe size of the map is too small (size of ");
	ft_putnbr(map_len);
	ft_putendl(")\nThe minimum size required is 3x3.");
	ft_putstr("\x1B[0m");
	return (-1);
}
