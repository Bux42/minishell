/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 03:27:59 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/06 16:19:53 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int			print_env(t_list **env, char **input)
{
	t_list	*cp;

	cp = (*env);
	if (input[1])
		check_input(input);
	else
	{
		while (cp)
		{
			ft_putendl(cp->content);
			cp = cp->next;
		}
	}
	return (1);
}

t_list		*chain_env(char **input)
{
	t_list		*chain;

	chain = NULL;
	if (!(chain = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	chain->content = new_env(input);
	chain->content_size = ft_strlen(chain->content);
	chain->next = NULL;
	return (chain);
}

int			unset_env(char **input, t_list **env)
{
	t_list	*cp;
	t_list	*tmp;

	tmp = NULL;
	cp = (*env);
	if (!input[1])
		return (1);
	while (cp)
	{
		if (matching_name(cp->content, input[1]))
		{
			if (tmp)
				return (remove_between(&cp, &tmp));
			else
				return (remove_first(env, &cp));
		}
		tmp = cp;
		cp = cp->next;
	}
	return (1);
}

int			set_env(char **input, t_list **env)
{
	int		i;
	t_list	*cp;

	i = -1;
	cp = (*env);
	if (!input[1])
		return (1);
	if (cp == NULL && ((*env) = chain_env(input)))
		return (1);
	while (cp)
	{
		if (matching_name(cp->content, input[1]))
		{
			free(cp->content);
			cp->content = new_env(input);
			return (1);
		}
		if (!cp->next)
			break ;
		cp = cp->next;
	}
	cp->next = chain_env(input);
	return (1);
}

t_list		*alloc_env(char **env)
{
	int		i;
	t_list	*new;
	char	*sh_lvl;

	i = -1;
	new = NULL;
	while (env[++i])
	{
		if (matching_name(env[i], "SHLVL"))
		{
			sh_lvl = shlvl(env[i]);
			ft_list_push_back(&new, sh_lvl, ft_strlen(sh_lvl) + 1);
			free(sh_lvl);
		}
		else
			ft_list_push_back(&new, env[i], ft_strlen(env[i]) + 1);
	}
	return (new);
}
