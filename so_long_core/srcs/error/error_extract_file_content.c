/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_extract_file_content.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:10:47 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/21 10:20:23 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	error_extract_file_content(t_file *file)
{
	ft_putstr("\x1B[31m");
	ft_putstr("ERROR\nA character not belonging to the given set (");
	ft_putstr(file->set);
	ft_putstr(") has been detected in the file [");
	ft_putstr(file->file_path);
	ft_putstr("] file line ");
	ft_putnbr((long)file->pos_y);
	ft_putstr(" character ");
	ft_putnbr((long)file->pos_x + 1);
	ft_putendl(".");
	close(file->file_descriptor);
	ft_memdel((void **)&file->line);
	ft_memdel((void **)&file->content);
	ft_putstr("\x1B[0m");
	return (-1);
}
