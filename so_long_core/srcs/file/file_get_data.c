/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_get_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:42:18 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/01 23:56:46 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	file_get_data(t_file *file, int line_can_be_empty)
{
	if (file_init_data(file) == -1)
		return (error_file_not_found(file->file_path));
	file->file_ext = file_get_ext(*file);
	if (file->file_ext == (void *)0)
		return (error_no_ext(file->file_descriptor));
	if (ft_strcmp(file->file_ext, EXT))
		return (error_bad_ext(file->file_ext, file->file_descriptor));
	success_file_found(file->file_path);
	file->content = (const char *)file_get_content(file, line_can_be_empty);
	if (file->content == (void *)0)
		return (error_extract_file_content(file));
	return (success_extract_file_content(file));
}
