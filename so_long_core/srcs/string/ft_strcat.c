/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:39:19 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/01 23:56:46 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t	dst_len;
	size_t	i;

	if (dst == (void *)0)
		return (NULL);
	if (src == (void *)0)
		return (dst);
	dst_len = ft_strlen(dst);
	i = 0;
	while (*src)
		dst[dst_len + i++] = *src++;
	dst[dst_len + i] = '\0';
	return (dst);
}
