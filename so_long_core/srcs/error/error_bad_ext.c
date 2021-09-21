/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bad_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:21:17 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/20 18:07:50 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	error_bad_ext(const char *ext, int file_descriptor)
{
	ft_putstr("\x1B[31m");
	ft_putstr("ERROR\nThe file extension must be [");
	ft_putstr(EXT);
	ft_putstr("] and not [");
	ft_putstr(ext);
	ft_putendl("].");
	close(file_descriptor);
	ft_putstr("\x1B[0m");
	return (-1);
}
