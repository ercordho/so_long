/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:06:39 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/15 00:26:14 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int	i;

	if (dst == NULL || src == NULL)
		return (NULL);
	i = -1;
	while (++i < (int)n)
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
	return (dst);
}
