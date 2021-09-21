/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:06:35 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/13 14:10:03 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

size_t	ft_putendl(const char *str)
{
	if (str == NULL)
		return (ft_putstr("(null)\n"));
	return (ft_putstr(str) + ft_putchar('\n'));
}
