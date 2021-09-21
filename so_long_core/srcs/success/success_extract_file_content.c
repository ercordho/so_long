/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   success_extract_file_content.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:12:39 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/15 02:59:01 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	success_extract_file_content(t_file *file)
{
	ft_putstr("\x1B[32m");
	ft_putendl("SUCCESS:");
	ft_putstr("the data in the [");
	ft_putstr(file->file_path);
	ft_putendl("] file has been correctly extracted.");
	ft_memdel((void **)&file->line);
	close(file->file_descriptor);
	ft_putstr("\x1B[0m");
	return (1);
}
