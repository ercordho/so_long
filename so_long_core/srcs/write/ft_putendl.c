/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:06:35 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/18 02:06:38 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

size_t	ft_putendl(const char *str)
{
	if (str == (void *)0)
	{
		if (__APPLE__)
			return (ft_putendl("(null)"));
		return (ft_putendl("(nil)"));
	}
	return (ft_putstr(str) + ft_putchar('\n'));
}
