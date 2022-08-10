/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhekim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 08:31:02 by minhekim          #+#    #+#             */
/*   Updated: 2022/08/10 08:51:33 by minhekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minhee.h"

int	set_stat(int *status, char **line, int fd)
{
	if ((fd < 0) || (line == 0))
		return (-1);
	*status = 1;
	*line = NULL;
	return (0);
}

int	gnl_malloc(char **buf)
{
	*buf = (char *)malloc(100 + 1);
	if (buf == NULL)
		return (-1);
	else
		return (0);
}

int	malloc_cat_saved(char **line, char **saved)
{
	*line = (char *)malloc(sizeof(char) * (get_len(*saved) + 1));
	if (*line == NULL)
		return (-1);
	(*line)[0] = '\0';
	return (0);
}

int	cat_saved(char **line, char **saved)
{
	char	*saved_cpy;

	if (malloc_cat_saved(line, saved) == -1)
		return (-1);
	ft_strcat(*line, *saved, 0);
	if (is_newline(*saved) == 1)
	{
		saved_cpy = ft_strdup(*saved);
		if (saved_cpy == NULL)
		{
			free(*saved);
			return (-1);
		}
		free(*saved);
		save_leftover(saved_cpy, saved);
		free(saved_cpy);
		return (2);
	}
	else
	{
		free(*saved);
		*saved = NULL;
		return (1);
	}
}
