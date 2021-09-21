/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 15:55:18 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/20 18:48:33 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	ft_isdigit(int c)
{
	if (c >= (int) '0' && c <= (int) '9')
		return (1);
	return (0);
}
