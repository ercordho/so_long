/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:10:56 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/01 23:56:46 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int	clean_memory(const char **paths, int val)
{
	ft_memdels((void **)&paths, (void **)paths);
	return (val);
}

static int	check_if_sprite_file_exist(const char *file_path)
{
	int	file_descriptor;

	file_descriptor = open(file_path, O_RDONLY);
	if (file_descriptor == -1)
		return (error_sprites_not_found(file_path));
	return (success_sprites_found(file_path));
}

static const char	**get_xpm_paths(int i)
{
	const char	**paths;

	paths = (const char **)malloc(sizeof(char *) * 6);
	if (paths == (void *)0)
		return (NULL);
	paths[0] = (const char *)ft_strdup(PLAYER);
	paths[1] = (const char *)ft_strdup(EXIT);
	paths[2] = (const char *)ft_strdup(ITEM);
	paths[3] = (const char *)ft_strdup(GROUND);
	paths[4] = (const char *)ft_strdup(WALL);
	paths[5] = NULL;
	while (paths[++i])
	{
		if (check_if_sprite_file_exist(paths[i]) == -1)
		{
			ft_memdels((void **)&paths, (void **)paths);
			return (NULL);
		}
		if (paths[i] == (void *)0)
		{
			ft_memdels((void **)&paths, (void **)paths);
			return (NULL);
		}
	}
	return (paths);
}

int	init_sprites(t_sprites *sprites, void *mlx_ptr, int i)
{
	int			x;
	int			y;
	size_t		paths_len;

	sprites->img = NULL;
	sprites->paths = get_xpm_paths(-1);
	if (sprites->paths == (void *)0)
		return (-1);
	paths_len = ft_strslen(sprites->paths);
	sprites->img = (t_img *)malloc(sizeof(t_img) * (paths_len + 1));
	if (sprites->img == (void *)0)
		return (clean_memory(sprites->paths, -1));
	while (sprites->paths[++i])
	{
		sprites->img[i].ptr = mlx_xpm_file_to_image(mlx_ptr, \
			(char *)sprites->paths[i], &x, &y);
		if (sprites->img[i].ptr == (void *)0)
			return (clean_memory(sprites->paths, -1));
		sprites->img[i].data = mlx_get_data_addr(sprites->img[i].ptr, \
			&sprites->img[i].bpp, &sprites->img[i].ll, &sprites->img[i].endian);
		if (sprites->img[i].data == (void *)0)
			return (clean_memory(sprites->paths, -1));
	}
	sprites->img[i].ptr = NULL;
	return (clean_memory(sprites->paths, 1));
}
