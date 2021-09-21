/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 00:21:12 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/17 00:22:05 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

size_t	ft_putstrs(const char **strs)
{
	size_t	size;
	int		i;

	if (strs == NULL)
		return (ft_putstr("(null"));
	size = 0;
	i = -1;
	while (strs[++i])
		size += ft_putstr(strs[i]);
	return (size);
}
