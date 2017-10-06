/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 23:08:05 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/06 14:52:52 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int		space_char(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	return (0);
}

int		count_words(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!space_char(s[i]))
		{
			count++;
			while (!space_char(s[i]) && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	*count_letters(int i, char *s)
{
	char	*ret;
	int		cp;
	int		pos;

	cp = i;
	pos = 1;
	while (s[i] && !space_char(s[i]))
	{
		i++;
		pos++;
	}
	if (!(ret = (char*)malloc(sizeof(char) * pos)))
		return (NULL);
	ret[pos - 1] = '\0';
	i = cp - 1;
	cp = 0;
	while (!space_char(s[++i]) && s[i])
	{
		ret[cp] = s[i];
		cp++;
	}
	return (ret);
}

int		right_pos(int j, char *s)
{
	int		i;
	int		k;

	k = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] && space_char(s[i]))
			while (s[i] && space_char(s[i]))
				i++;
		if (s[i] && !space_char(s[i]))
		{
			if (k == j)
				return (i);
			while (s[i] && !space_char(s[i]))
				i++;
			k++;
		}
	}
	return (i);
}

char	**custom_split(char *s)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = (char**)malloc(sizeof(char*) * (count_words(s) + 1))))
		return (NULL);
	while (i < count_words(s))
	{
		str[i] = count_letters(right_pos(i, s), s);
		i++;
	}
	str[i] = NULL;
	return (str);
}
