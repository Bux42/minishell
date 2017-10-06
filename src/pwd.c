/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 05:34:34 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/06 16:26:45 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int			prompt(void)
{
	char	*pwd;

	if ((pwd = custom_pwd()))
	{
		ft_putstr(pwd);
		free(pwd);
	}
	ft_putstr("$> ");
	return (1);
}

int			print_pwd(void)
{
	char	*pwd;

	pwd = custom_pwd();
	ft_putendl(pwd);
	free(pwd);
	return (1);
}

char		*custom_pwd(void)
{
	char	*buff;

	if (!(buff = (char*)malloc(sizeof(char) * 2048)))
		return (NULL);
	if ((getcwd(buff, 2048)))
		return (buff);
	return (NULL);
}

void		update_newpwd(t_list **env, char *new)
{
	t_list	*cp;
	char	**input;

	if (!(input = (char**)malloc(sizeof(char*) * 4)))
		return ;
	input[0] = ft_strdup("setenv");
	input[1] = ft_strdup("OLDPWD");
	input[2] = ft_strdup(new);
	input[3] = NULL;
	cp = (*env);
	while (cp)
	{
		if (matching_name(cp->content, "OLDPWD"))
		{
			free(cp->content);
			cp->content = new_env(input);
			break ;
		}
		cp = cp->next;
	}
	free_char_array(input);
}
