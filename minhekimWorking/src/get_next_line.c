/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhekim <minhekim@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:17:25 by minhekim          #+#    #+#             */
/*   Updated: 2022/08/10 08:52:41 by minhekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minhee.h"

int	cat_buf(char **line, char *buf, int bytes_read)
{
	char	*tmp;
	int		line_len;
	int		buf_len;

	buf[bytes_read] = '\0';
	line_len = ft_strlen(*line);
	buf_len = get_len(buf);
	tmp = (char *)malloc(line_len + buf_len + 1);
	tmp[0] = '\0';
	ft_strcat(tmp, *line, 0);
	ft_strcat(tmp, buf, line_len);
	free(*line);
	*line = tmp;
	return (1);
}

int	save_leftover(char *buf, char **saved)
{
	int		i;
	int		j;

	i = 0;
	while (buf[i] != '\n')
		i++;
	i++;
	*saved = (char *)malloc(sizeof(char) * (ft_strlen(buf) - i + 1));
	if (*saved == NULL)
		return (-2);
	j = 0;
	while (buf[i] != '\0')
	{
		(*saved)[j] = buf[i];
		j++;
		i++;
	}
	(*saved)[j] = '\0';
	return (1);
}

int	return_stat(int status, char **line, char *buf)
{
	free(buf);
	if (status == 0)
	{
		if (*line == NULL)
		{
			*line = (char *)malloc(1);
			(*line)[0] = '\0';
		}
		return (0);
	}
	else if (status == 2)
		return (1);
	else
	{
		free(*line);
		return (-1);
	}
}

int	get_return(int bytes_read, int status, char **line, char *buf)
{
	if (bytes_read <= 0)
		return (return_stat(bytes_read, line, buf));
	else
		return (return_stat(status, line, buf));
}

int	get_next_line(int fd, char **line)
{
	static char	*saved = NULL;
	char		*buf;
	int			bytes_read;
	int			status;

	if (set_stat(&status, line, fd))
		return (-1);
	if (saved != NULL)
	{
		status = cat_saved(line, &saved);
		if (status == 2)
			return (1);
	}
	if (gnl_malloc(&buf) == -1)
		return (-1);
	bytes_read = read(fd, buf, 100);
	while (status == 1 && bytes_read > 0)
	{
		status = cat_buf(line, buf, bytes_read);
		if (status == 1 && is_newline(buf) == 1)
			status += save_leftover(buf, &saved);
		else
			bytes_read = read(fd, buf, 100);
	}
	return (get_return(bytes_read, status, line, buf));
}
