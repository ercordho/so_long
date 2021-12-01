/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_number_recurrence_groups.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:13:25 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/01 23:56:46 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	count_number_recurrence_groups(const char *str, const char *set)
{
	int	count;
	int	ret;

	if (str == (void *)0 || set == (void *)0)
		return (0);
	count = 0;
	ret = 0;
	while (*str)
	{
		if (ft_ischarset(set, *str) >= 0)
			ret = 0;
		else
		{
			if (ret == 0)
				count++;
			ret = 1;
		}
		str++;
	}
	return (count);
}
