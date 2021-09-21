/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:34:02 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/21 10:55:17 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	init_map(t_map *map, const char *map_content)
{
	if (ft_strlen(map_content) == 0)
		return (error_map_is_empty());
	map->content = ft_split(map_content, "\n");
	if (map->content == NULL)
		return (-1);
	map->length = (int)ft_strslen((const char **)map->content);
	if (map->length < 3)
		return (error_map_is_too_small((long)map->length));
	map->walkable_surface = 0;
	map->is_finish = -1;
	map->pos_y = -1;
	map->pos_x = -1;
	map->count_of_player = 0;
	map->count_of_exit = 0;
	map->count_of_item = 0;
	map->count_of_empty = 0;
	map->count_of_move = 0;
	return (1);
}
