/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 06:43:15 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/03 06:43:23 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int			color(char **input)
{
	if (!input[1])
		ft_putendl("No color speficied");
	else
	{
		if (ft_strcmp(input[1], "red") == 0)
			ft_putstr("\x1b[31m");
		else if (ft_strcmp(input[1], "green") == 0)
			ft_putstr("\x1b[32m");
		else if (ft_strcmp(input[1], "yellow") == 0)
			ft_putstr("\x1b[33m");
		else if (ft_strcmp(input[1], "blue") == 0)
			ft_putstr("\x1b[34m");
		else if (ft_strcmp(input[1], "pink") == 0)
			ft_putstr("\x1b[35m");
		else if (ft_strcmp(input[1], "cyan") == 0)
			ft_putstr("\x1b[36m");
		else if (ft_strcmp(input[1], "reset") == 0)
			ft_putstr("\x1b[37m");
	}
	return (1);
}
