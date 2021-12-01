/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 00:21:12 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/01 23:56:18 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

size_t	ft_putstrs(const char **strs)
{
	size_t	size;
	int		i;

	if (strs == (void *)0)
	{
		if (__APPLE__)
			return (ft_putstr("(null"));
		return (ft_putstr("(nil)"));
	}
	size = 0;
	i = -1;
	while (strs[++i])
		size += ft_putstr(strs[i]);
	return (size);
}
