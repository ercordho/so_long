/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:37:37 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/13 22:44:51 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_memdels(void **ptr, void **content)
{
	if (ptr && content)
	{
		while (*content)
			ft_memdel(&(*content++));
		ft_memdel(&(*ptr));
	}
}
