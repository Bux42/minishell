/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 05:01:40 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/06 17:24:35 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void		add_env_exe(char **input, int i, t_list *chain)
{
	pid_t	father;
	char	**env;

	father = fork();
	if (father == 0)
	{
		env = list_to_char(&chain);
		if (!path_exe(input[i - 1]))
		{
			command_error(input[i - 1]);
			exit(1);
		}
		if ((execve(input[i - 1], input, env)) == -1)
		{
			command_error(input[i - 1]);
			exit(1);
		}
	}
	else
		wait(&father);
	if (chain)
		free_list(chain);
}

int			contains_env(t_list **env, char *prefix)
{
	t_list	*cp;

	cp = (*env);
	while (cp)
	{
		if (matching_name(cp->content, prefix))
			return (1);
		cp = cp->next;
	}
	return (0);
}

int			remove_between(t_list **cp, t_list **tmp)
{
	(*tmp)->next = (*cp)->next;
	free((*cp)->content);
	free((*cp));
	return (1);
}

int			remove_first(t_list **env, t_list **cp)
{
	(*env) = (*env)->next;
	free((*cp)->content);
	free((*cp));
	return (1);
}
