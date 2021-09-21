/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 03:13:35 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/20 18:49:27 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int	parse_map_check(t_map *map)
{
	if (map->count_of_player != 1)
		return (error_parse_map_count_of_player((long)map->count_of_player));
	if (map->count_of_exit != 1)
		return (error_parse_map_count_of_exit((long)map->count_of_exit));
	if (map->count_of_item == 0)
		return (error_parse_map_count_of_item());
	if (map->length == map->pos_x)
		return (error_map_isnt_rectangular((long)map->pos_x, (long)map->pos_y));
	return (success_map_check((const char **)map->content));
}

static void	parse_map_update(t_map *map, char c)
{
	if (c == 'P')
	{
		map->player_pos = (t_dot){map->pos_x, map->pos_y, 0};
		map->count_of_player++;
	}
	if (c == 'E')
		map->count_of_exit++;
	if (c == 'C')
		map->count_of_item++;
	if (c == '0')
		map->count_of_empty++;
}

static int	parse_map_line(t_map *map, const char *line)
{
	static size_t	line_len = 0;

	if (line_len > 0)
		if (line_len != ft_strlen(line))
			return (error_parse_map_len(*map, (long)ft_strlen(line)));
	line_len = ft_strlen(line);
	if (line_len < 3)
		return (error_parse_map_min_len(map->pos_y + 1, line_len));
	map->pos_x = -1;
	while (line[++map->pos_x])
	{
		if (map->pos_y == 0 || map->pos_y == map->length - 1)
		{
			if (line[map->pos_x] != '1')
				return (error_parse_map_uppper_lower(*map));
		}
		else
		{
			if (line[0] != '1' || line[line_len - 1] != '1')
				return (error_parse_map_side(*map));
		}
		parse_map_update(map, line[map->pos_x]);
	}
	return (1);
}

int	parse_map(t_map *map, const char *map_content)
{
	if (init_map(map, map_content) == -1)
		return (-1);
	while (map->content[++map->pos_y])
	{
		if (parse_map_line(map, (const char *)map->content[map->pos_y]) == -1)
		{
			ft_memdels((void **)&map->content, (void **)map->content);
			return (-1);
		}
	}
	if (parse_map_check(map) == -1)
	{
		ft_memdels((void **)&map->content, (void **)map->content);
		return (-1);
	}
	map->walkable_surface = map->count_of_item + map->count_of_empty + 1;
	ft_memdel((void **)&map_content);
	return (1);
}
