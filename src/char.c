/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 03:56:46 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/06 15:03:03 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int				contains(char *str, char c)
{
	int		i;

	i = -1;
	if (str)
	{
		while (str[++i])
			if (str[i] == c)
				return (1);
	}
	return (0);
}

char			*bin_path(char *path, char *command)
{
	char	*ret;
	int		size;
	int		i;

	i = -1;
	size = ft_strlen(path) + ft_strlen(command) + 2;
	if (!(ret = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(ret, size);
	ft_strcat(ret, path);
	ft_strcat(ret, "/");
	ft_strcat(ret, command);
	return (ret);
}

char			*variable_path(char *name, char *value)
{
	char	*ret;
	int		len;
	int		dec;

	dec = -1;
	len = ft_strlen(name) + ft_strlen(value) + 1;
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ret[len] = '\0';
	len = -1;
	while (name[++len])
		ret[len] = name[len];
	ret[len] = '=';
	len++;
	while (value[++dec])
	{
		ret[len] = value[dec];
		len++;
	}
	free(value);
	return (ret);
}

char			*replace_input(char *content)
{
	int		i;
	int		j;
	int		len;
	char	*ret;

	i = -1;
	j = 0;
	len = 0;
	while (content[++i])
		if (content[i] == '=')
			break ;
	while (content[++i])
		len++;
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (content[i - len])
	{
		ret[j] = content[i - len];
		j++;
		len--;
	}
	ret[j] = '\0';
	return (ret);
}
