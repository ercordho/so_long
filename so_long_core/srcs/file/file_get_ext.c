/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_get_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 02:01:12 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/20 18:48:46 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int	file_get_ext_start_pos(t_file file)
{
	int	pos;

	pos = 0;
	if (file.file_path[pos] == '~')
		pos++;
	while (file.file_path[pos])
	{
		if (ft_strncmp(file.file_path + pos, "../", 3) == 0)
			pos += 3;
		else if (ft_strncmp(file.file_path + pos, "./", 2) == 0)
			pos += 2;
		else if (ft_isalnum((int)file.file_path[pos]) == 1)
			pos++;
		else if (ft_ischarset("-_/", file.file_path[pos]) > -1)
			pos++;
		else if (file.file_path[pos] == '.')
		{
			if (file.file_path[pos + 1] == '\0')
				return (-1);
			if (ft_isalnum((int)file.file_path[pos + 1]) == 0)
				return (-1);
			return (pos);
		}
	}
	return (-1);
}

const char	*file_get_ext(t_file file)
{
	int	pos;

	pos = file_get_ext_start_pos(file);
	if (pos == -1)
		return (NULL);
	return (file.file_path + pos);
}
