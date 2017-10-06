/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 05:18:00 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/06 16:29:14 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

char		*get_home(t_list **env)
{
	char	*ret;
	t_list	*cp;

	cp = (*env);
	ret = NULL;
	while (cp)
	{
		if ((ret = ft_strstr(cp->content, "HOME")))
			return (ret);
		cp = cp->next;
	}
	return (ret);
}

int			oldpwd(t_list **env)
{
	t_list	*cp;

	cp = (*env);
	while (cp)
	{
		if (matching_name(cp->content, "OLDPWD"))
		{
			custom_chdir(&cp->content[7], env);
			return (1);
		}
		cp = cp->next;
	}
	return (1);
}

void		custom_chdir(char *path, t_list **env)
{
	t_list	*cp;
	char	*tmp;

	cp = (*env);
	if (!(tmp = custom_pwd()))
		free(tmp);
	if (chdir(path) == -1)
	{
		path_error(path);
		free(tmp);
	}
	else
	{
		artificial_setenv("PWD", custom_pwd(), env);
		if (tmp)
			artificial_setenv("OLDPWD", tmp, env);
	}
}

void		change_custom_dir(char *home, char *path, t_list **env)
{
	int		len;
	char	*tmp;
	int		i;

	i = 1;
	len = ft_strlen(&home[5]) + ft_strlen(path);
	home[ft_strlen(home) - 1] != '/' ? len++ : 0;
	if (!(tmp = (char*)malloc(sizeof(char) * len)))
		return ;
	ft_bzero(tmp, len);
	ft_strcat(tmp, &home[5]);
	if (home[ft_strlen(home) - 1] != '/')
		ft_strcat(tmp, "/");
	len = ft_strlen(tmp);
	while (path[++i])
	{
		tmp[len] = path[i];
		len++;
	}
	custom_chdir(tmp, env);
	free(tmp);
}

int			change_dir(char *path, t_list **env)
{
	char	*home;

	if (path && ft_strcmp(path, "-") == 0)
		return (oldpwd(env));
	if (!path || path[0] == '~')
	{
		if ((home = get_home(env)))
		{
			if (!path)
				custom_chdir(&home[5], env);
			else if ((path[1] == '/' && !path[2]) || !path[1])
			{
				if ((home = get_home(env)))
					custom_chdir(&home[5], env);
			}
			else
				change_custom_dir(home, path, env);
		}
		else
			return (path_error(path));
	}
	else
		custom_chdir(path, env);
	return (1);
}
