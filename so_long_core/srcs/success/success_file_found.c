/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   success_file_found.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:12:33 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/13 19:46:38 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	success_file_found(const char *file_path)
{
	ft_putstr("\x1B[32m");
	ft_putstr("SUCCESS:\nThe file [");
	ft_putstr(file_path);
	ft_putendl("] was successsfully opened.");
	ft_putstr("\x1B[0m");
	return (1);
}
