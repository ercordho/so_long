/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   success_sprites_found.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 01:45:50 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/17 01:52:53 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	success_sprites_found(const char *file_path)
{
	ft_putstr("\x1B[32m");
	ft_putstr("SUCCESS:\nThe sprite file [");
	ft_putstr(file_path);
	ft_putendl("] was found.");
	ft_putstr("\x1B[0m");
	return (1);
}
