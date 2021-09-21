/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischarset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:09:09 by ercordho          #+#    #+#             */
/*   Updated: 2021/08/30 18:17:59 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	ft_ischarset(const char *set, char c)
{
	int		i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (i);
	}
	return (-1);
}
