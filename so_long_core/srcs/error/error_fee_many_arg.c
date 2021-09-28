/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_fee_many_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:45:31 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/28 13:51:40 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	error_fee_many_arg(int argc)
{
	ft_putstr("\x1B[31m");
	ft_putstr("ERROR\n2 arguments are expected for the correct functioning ");
	ft_putstr(" of the program (currently ");
	ft_putnbr((long)argc);
	ft_putendl(").");
	ft_putendl("Format [./so_long path/of/the/map].");
	ft_putstr("\x1B[0m");
	return (-1);
}
