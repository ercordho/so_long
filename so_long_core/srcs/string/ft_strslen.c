/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strslen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:59:47 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/01 23:56:46 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

size_t	ft_strslen(const char **strs)
{
	size_t	len;

	if (strs == (void *)0)
		return (0);
	len = 0;
	while (strs[len])
		len++;
	return (len);
}
