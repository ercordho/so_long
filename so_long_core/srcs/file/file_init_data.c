/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_init_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:07:50 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/18 15:03:54 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	file_init_data(t_file *file)
{
	file->pos_y = 0;
	file->line = NULL;
	file->file_descriptor = open(file->file_path, O_RDONLY);
	return (file->file_descriptor);
}
