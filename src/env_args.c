/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 10:36:16 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/06 17:24:36 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void		illegal_option(char *str)
{
	ft_putstr("env: illegal option -- ");
	ft_putendl(str);
	ft_putendl("usage: env [-i] [name=value] [argument]");
}

int			valid_env(char *str)
{
	if (ft_strlen(str) > 2)
		if (str[0] != '=')
			if (contains(str, '='))
				return (1);
	ft_putstr(str);
	ft_putendl(" is not a valid env");
	return (0);
}

void		free_list(t_list *env)
{
	if (env)
	{
		free_list(env->next);
		free(env->content);
		free(env);
	}
}

void		add_env(char **input)
{
	int		i;
	t_list	*chain;

	chain = NULL;
	i = 1;
	while (input[++i])
		if (input[i + 1])
			if (valid_env(input[i]))
				ft_list_push_back(&chain, input[i], ft_strlen(input[i]) + 1);
	add_env_exe(input, i, chain);
}

void		check_input(char **input)
{
	pid_t	father;

	g_ctrl = 0;
	if (ft_strcmp(input[1], "-i") == 0)
	{
		if (input[2] && path_exe(input[2]))
		{
			father = fork();
			if (father == 0)
			{
				if ((execve(input[2], input, NULL)) == -1)
				{
					command_error(input[2]);
					exit(1);
				}
			}
			else
				wait(&father);
		}
		else
			add_env(input);
	}
	else
		illegal_option(input[1]);
	g_ctrl = 1;
}
