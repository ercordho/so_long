/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   success_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 00:12:29 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/17 00:33:13 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	success_map_check(const char **map)
{
	ft_putstr("\x1B[32m");
	ft_putendl("SUCCESS:\nThe map has been correctly parsed and is valid.");
	ft_putendls(map);
	ft_putendl("Good Game :)");
	ft_putstr("\x1B[0m");
	return (1);
}
