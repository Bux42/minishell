/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 23:08:05 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/04 11:11:06 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/libft.h"

static	int		ft_count_words(const char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static	int		right_pos(const char *s, char c, int j)
{
	int		i;
	int		k;

	k = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] && s[i] == c)
			while (s[i] && s[i] == c)
				i++;
		if (s[i] && s[i] != c)
		{
			if (k == j)
				return (i);
			while (s[i] && s[i] != c)
				i++;
			k++;
		}
	}
	return (i);
}

static	char	*ft_count_letters(const char *s, int i, char c)
{
	char	*ret;
	int		cp;
	int		pos;

	cp = i;
	pos = 1;
	while (s[i] && s[i] != c)
	{
		i++;
		pos++;
	}
	if (!(ret = (char*)malloc(sizeof(char) * pos)))
		return (NULL);
	ret[pos - 1] = '\0';
	i = cp - 1;
	cp = 0;
	while (s[i] && s[++i] != c)
	{
		ret[cp] = s[i];
		cp++;
	}
	return (ret);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**str;
	int		i;

	i = 0;
	if (s == NULL || c == 0)
		return (NULL);
	if (!(str = (char**)malloc(sizeof(char*) * (ft_count_words(s, c) + 1))))
		return (NULL);
	while (i < ft_count_words(s, c))
	{
		str[i] = ft_count_letters(s, right_pos(s, c, i), c);
		i++;
	}
	str[i] = 0;
	return (str);
}
