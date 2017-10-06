/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 04:41:34 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/06 10:35:25 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int			f_echo(char *input)
{
	ft_putendl(&input[5]);
	return (1);
}

void		update_env(t_list *cp, char *env, char *value)
{
	free(cp->content);
	cp->content = variable_path(env, value);
}

int			special_command(char **input, t_list **env, char *str)
{
	if (ft_strcmp("env", input[0]) == 0)
		return (print_env(env, input));
	if (ft_strcmp("setenv", input[0]) == 0)
		return (set_env(input, env));
	if (ft_strcmp("unsetenv", input[0]) == 0)
		return (unset_env(input, env));
	if (ft_strcmp("cd", input[0]) == 0)
		return (change_dir(input[1], env));
	if (ft_strcmp("pwd", input[0]) == 0)
		return (print_pwd());
	if (ft_strcmp("echo", input[0]) == 0)
		return (f_echo(str));
	if (ft_strcmp("color", input[0]) == 0)
		return (color(input));
	return (0);
}
