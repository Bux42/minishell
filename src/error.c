/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 05:26:47 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/06 17:24:37 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int			command_error(char *command)
{
	ft_putstr("zsh: command not found: ");
	ft_putendl(command);
	return (1);
}

int			path_error(char *name)
{
	ft_putstr("cd: no such file or directory: ");
	ft_putendl(name);
	return (1);
}

int			path_exe(char *str)
{
	int		i;
	int		gud;

	i = -1;
	gud = 0;
	while (str[++i])
		if (str[i] == '/')
			gud++;
	if (gud && access(str, X_OK) == 0)
		return (1);
	return (0);
}
