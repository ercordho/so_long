/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parse_map_count_of_item.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 00:03:09 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/20 18:07:50 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	error_parse_map_count_of_item(void)
{
	ft_putstr("\x1B[31m");
	ft_putendl("ERROR\n0 item was found (flag C).");
	ft_putstr("\x1B[0m");
	return (-1);
}
