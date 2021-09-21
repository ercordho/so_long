/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 15:33:50 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/21 10:12:47 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	parse_file(t_file *file, const char *set, const char *file_path)
{
	file->set = set;
	file->file_path = file_path;
	file->content = NULL;
	if (file_get_data(file, -1) == -1)
		return (-1);
	return (1);
}
