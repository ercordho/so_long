/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parse_map_count_of_exit.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 00:01:16 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/20 18:07:50 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	error_parse_map_count_of_exit(long count_of_exit)
{
	ft_putstr("\x1B[31m");
	ft_putstr("ERROR\nThe number of exit present on the map is ");
	if (count_of_exit < 0)
		ft_putstr("less ");
	else
		ft_putstr("greater ");
	ft_putendl("than 1.");
	ft_putnbr(count_of_exit);
	ft_putendl(" exit(s) detected.");
	ft_putendl("while only 1 exit can be present on the map (flag E).");
	ft_putstr("\x1B[0m");
	return (-1);
}
