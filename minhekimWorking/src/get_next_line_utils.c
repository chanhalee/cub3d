/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhekim <minhekim@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:27:05 by minhekim          #+#    #+#             */
/*   Updated: 2022/08/10 08:51:16 by minhekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minhee.h"

int	is_newline(char *buf)
{
	int		i;

	i = 0;
	while (i < 100 && buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_strcat(char *str1, char *str2, int start)
{
	int		j;

	if (str1 == NULL || str2 == NULL)
		return ;
	j = 0;
	while (str2[j] != '\0' && str2[j] != '\n')
	{
		str1[start] = str2[j];
		start++;
		j++;
	}
	str1[start] = '\0';
}

char	*ft_strdup(char *str)
{
	char	*ret;
	int		i;

	ret = (char *)malloc((ft_strlen(str) + 1));
	if (ret == NULL)
		return (ret);
	i = 0;
	if (str == NULL)
		ret[i] = '\0';
	else
	{
		while (str[i] != '\0')
		{
			ret[i] = str[i];
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}

int	get_len(char *str)
{
	int		i;

	i = 0;
	while (str != NULL && str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}
