/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 03:44:44 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/06 15:30:22 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void		artificial_setenv(char *env, char *path, t_list **env2)
{
	char	**input;

	if (!(input = (char**)malloc(sizeof(char*) * 4)))
		return ;
	input[0] = ft_strdup("setenv");
	input[1] = ft_strdup(env);
	input[2] = ft_strdup(path);
	input[3] = NULL;
	set_env(input, env2);
	free(path);
	free_char_array(input);
}

char		**get_path(t_list **env)
{
	int		i;
	char	*result;
	char	**ret;
	t_list	*cp;

	i = -1;
	ret = NULL;
	cp = (*env);
	while (cp)
	{
		if ((result = ft_strstr(cp->content, "PATH=")))
		{
			ret = ft_strsplit(&result[5], ':');
			return (ret);
		}
		cp = cp->next;
	}
	return (ret);
}

char		**list_to_char(t_list **chain)
{
	t_list	*cp;
	char	**env;
	int		i;

	cp = (*chain);
	i = 0;
	while (cp)
	{
		i++;
		cp = cp->next;
	}
	if (!(env = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	cp = (*chain);
	env[i] = NULL;
	i = 0;
	while (cp)
	{
		env[i] = ft_strdup(cp->content);
		cp = cp->next;
		i++;
	}
	return (env);
}

int			replace_var(char **input, t_list **env)
{
	t_list	*cp;
	int		i;

	i = -1;
	while (input[++i])
	{
		cp = (*env);
		if (input[i][0] == '$')
		{
			while (cp)
			{
				if (matching_name(cp->content, &input[i][1]))
				{
					free(input[i]);
					input[i] = replace_input(cp->content);
					break ;
				}
				cp = cp->next;
			}
		}
	}
	return (1);
}

void		free_char_array(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
		free(env[i]);
	free(env);
}
