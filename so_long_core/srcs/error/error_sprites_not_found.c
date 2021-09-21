/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_sprites_not_found.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 01:43:30 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/20 18:07:50 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	error_sprites_not_found(const char *file_path)
{
	ft_putstr("\x1B[31m");
	ft_putstr("ERROR\nThe sprite file [");
	ft_putstr(file_path);
	ft_putendl("] was not found.");
	ft_putstr("\x1B[0m");
	return (-1);
}
