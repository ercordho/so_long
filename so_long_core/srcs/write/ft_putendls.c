/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 00:17:35 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/01 23:56:03 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

size_t	ft_putendls(const char **strs)
{
	size_t	size;
	int		i;

	if (strs == (void *)0)
	{
		if (__APPLE__)
			return (ft_putendl("(null"));
		return (ft_putendl("(nil)"));
	}
	size = 0;
	i = -1;
	while (strs[++i])
		size += ft_putendl(strs[i]);
	return (size);
}
