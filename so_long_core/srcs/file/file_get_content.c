/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_get_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 02:03:24 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/01 23:56:46 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int	line_is_valid(t_file *file, int line_can_be_empty)
{
	int		i;

	file->pos_x = 0;
	file->pos_y++;
	if (file->line == (void *)0)
		return (-1);
	if (*file->line == '\0')
	{
		if (line_can_be_empty == -1)
			return (-1);
		return (1);
	}
	i = -1;
	while (file->line[++i])
	{
		if (ft_ischarset(file->set, file->line[i]) == -1)
			return (-1);
		file->pos_x++;
	}
	return (1);
}

static char	*file_get_first_nodes(t_file *file, int line_can_be_empty)
{
	char	*content;
	int		i;

	if (line_is_valid(file, line_can_be_empty) == -1)
		return (NULL);
	content = (char *)ft_memsetmal('\0', ft_strlen(file->line) + 2);
	if (content == (void *)0)
		return (NULL);
	i = -1;
	while (file->line[++i])
		content[i] = file->line[i];
	content[i++] = '\n';
	return (content);
}

static char	*file_get_nodes(char *content, t_file *file, int line_can_be_empty)
{
	size_t	content_len;
	size_t	total_len;

	if (line_is_valid(file, line_can_be_empty) == -1)
		return (NULL);
	content_len = ft_strlen(content);
	total_len = content_len + ft_strlen(file->line) + 2;
	content = ft_realloc(content, total_len, content_len);
	if (content == (void *)0)
		return (NULL);
	content = ft_strcat(content, file->line);
	if (content == (void *)0)
		return (NULL);
	return (content);
}

char	*file_get_content(t_file *file, int line_can_be_empty)
{
	char	*content;

	content = NULL;
	while (get_next_line(file->file_descriptor, &file->line) > 0)
	{
		if (content == (void *)0)
			content = file_get_first_nodes(file, line_can_be_empty);
		else
		{
			content = file_get_nodes(content, file, line_can_be_empty);
			if (content)
				content[ft_strlen(content)] = '\n';
		}
		if (content == (void *)0)
			return (NULL);
		ft_memdel((void **)&file->line);
	}
	content = file_get_nodes(content, file, line_can_be_empty);
	if (content == (void *)0)
		return (NULL);
	return (content);
}
