/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 03:24:08 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/06 17:08:47 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void		exe_bin(t_bin bin, t_list **env, char **input)
{
	bin.father = fork();
	if (bin.father == 0)
	{
		bin.env2 = list_to_char(env);
		bin.exe = bin_path(bin.binpath[bin.i], bin.fl->d_name);
		if ((execve(bin.exe, input, bin.env2)) == -1)
		{
			command_error(input[0]);
			exit(1);
		}
		free(bin.exe);
		free_char_array(bin.env2);
	}
	wait(&bin.father);
}

void		find_bin(t_list **env, char **input)
{
	t_bin	bin;

	bin.i = -1;
	bin.s = 0;
	if (!(bin.binpath = get_path(env)))
		return ((void)command_error(input[0]));
	else
	{
		while (bin.binpath[++bin.i])
		{
			if ((bin.od = opendir(bin.binpath[bin.i])))
			{
				while ((bin.fl = readdir(bin.od)))
					if (ft_strcmp(input[0], bin.fl->d_name) == 0 && ++bin.s)
						exe_bin(bin, env, input);
				closedir(bin.od);
			}
		}
	}
	if (bin.binpath[0])
		free_char_array(bin.binpath);
	if (!bin.s)
		command_error(input[0]);
}

void		routine(t_list **env, char **input)
{
	pid_t	father;
	char	**env2;

	g_ctrl = 0;
	if (path_exe(input[0]))
	{
		father = fork();
		if (father == 0)
		{
			env2 = list_to_char(env);
			if ((execve(input[0], input, env2)) == -1)
			{
				command_error(input[0]);
				exit(1);
			}
		}
		wait(&father);
	}
	else
		find_bin(env, input);
	g_ctrl = 1;
}

void		signal_event(int signo)
{
	if (signo == SIGINT && g_ctrl == 1)
	{
		ft_putchar('\n');
		prompt();
	}
}

int			main(int ac, char **av, char **env)
{
	char	*str;
	char	**input;
	t_list	*chain;

	chain = alloc_env(env);
	signal(SIGINT, signal_event);
	g_ctrl = 1;
	while (prompt() && get_next_line(0, &str) && ac && av)
	{
		if (str && str[0])
		{
			input = custom_split(str);
			if (ft_strlen(input[0]) && replace_var(input, &chain))
			{
				if (ft_strcmp(input[0], "exit") == 0)
					return (0);
				if (!special_command(input, &chain, str))
					routine(&chain, input);
			}
			free_char_array(input);
		}
		free(str);
	}
	return (0);
}
