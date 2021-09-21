/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsetmal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 01:20:38 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/15 01:24:11 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	*ft_memsetmal(int c, size_t len)
{
	void	*ptr;

	ptr = malloc(sizeof(void) * len);
	if (ptr == NULL)
		return (NULL);
	return (ft_memset(ptr, c, 0, len));
}
