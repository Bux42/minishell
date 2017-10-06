/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_str_manip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 03:31:27 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/03 04:58:30 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

char		*new_env(char **input)
{
	char	*ret;
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(input[1]) + ft_strlen(input[2]);
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ret[len] = '\0';
	len = -1;
	while (input[1][++len])
		ret[len] = input[1][len];
	ret[len] = '=';
	while (input[2] && input[2][++i])
		ret[++len] = input[2][i];
	return (ret);
}

char		*shlvl(char *content)
{
	char	*ret;
	char	*ito;
	int		value;
	int		len;

	value = ft_atoi(&content[6]);
	len = 1;
	value++;
	ito = ft_itoa(value);
	while (value > 9)
	{
		value /= 10;
		len++;
	}
	if (!(ret = (char*)malloc(sizeof(char) * len + 7)))
		return (NULL);
	ft_bzero(ret, len + 7);
	ft_strcat(ret, "SHLVL=");
	ft_strcat(ret, ito);
	free(ito);
	return (ret);
}

int			matching_name(char *env, char *name)
{
	int		i;

	i = 0;
	while (env[i] == name[i])
		i++;
	if (env[i] == '=' && name[i] == '\0')
		return (1);
	return (0);
}
