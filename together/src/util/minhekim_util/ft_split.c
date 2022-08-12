/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:26:11 by minhekim          #+#    #+#             */
/*   Updated: 2022/08/12 13:12:47 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

unsigned int	word_cnt(char const *s, char c)
{
	unsigned int	ret;
	unsigned int	i;

	ret = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			ret++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (ret);
}

static	unsigned int	letter_cnt(char const *s, char c)
{
	unsigned int	ret;

	ret = 0;
	while (*s && *s != c)
	{
		s++;
		ret++;
	}
	return (ret);
}

static	char			**ft_error(char **table)
{
	unsigned int	i;

	i = 0;
	while (table[i])
		free(table[i++]);
	free(table);
	return (0);
}

char					**ft_split(char const *s, char c)
{
	char			**table;
	unsigned int	wc;
	unsigned int	lc;
	unsigned int	i;

	if (!s)
		return (0);
	wc = word_cnt(s, c);
	if (!(table = (char **)ft_calloc(wc + 1, sizeof(char *))))
		return (0);
	i = 0;
	while (i++ < wc)
	{
		while (*s && *s == c)
			s++;
		lc = letter_cnt(s, c);
		if (!(table[i - 1] = (char *)ft_calloc(lc + 1, sizeof(char))))
			return (ft_error(table));
		ft_strlcpy(table[i - 1], s, lc + 1);
		s += lc;
	}
	return (table);
}
