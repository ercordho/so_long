/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:18:38 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/28 14:10:22 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	ft_swap(void *a, void *b)
{
	void	*tmp;

	tmp = ft_memsetmal('\0', sizeof(void) * 1);
	if (tmp == NULL)
		return ;
	ft_memcpy(tmp, a, 1);
	ft_memcpy(a, b, 1);
	ft_memcpy(b, tmp, 1);
	ft_memdel(&tmp);
}

void	ft_strrev(char *str)
{
	size_t	str_len;
	int		i;
	int		j;

	str_len = ft_strlen((const char *)str);
	i = -1;
	while (++i < (int)str_len / 2)
	{
		j = (int)str_len - i - 1;
		ft_swap(&str[i], &str[j]);
	}
}

int	main(int argc, char **argv)
{
	t_file	file;
	t_map	map;
	
	if (argc == 2)
	{
		if (parse_file(&file, SET, argv[1]) == -1)
		{
			ft_memdel((void **)&file.content);
			system("leaks so_long");
			exit(EXIT_FAILURE);
		}
		if (parse_map(&map, file.content) == -1)
		{
			ft_memdel((void **)&file.content);
			system("leaks so_long");
			exit(EXIT_FAILURE);
		}
		if (so_long(map) == -1)
		{
			system("leaks so_long");
			exit(EXIT_FAILURE);
		}
	}
	else
		error_fee_many_arg(argc);
	system("leaks so_long");
	exit(EXIT_FAILURE);
}
