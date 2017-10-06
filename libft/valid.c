/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 14:44:43 by videsvau          #+#    #+#             */
/*   Updated: 2017/09/27 15:11:02 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/libft.h"

int			valid(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < 32 && str[i] > 126)
			return (0);
	}
	return (1);
}
