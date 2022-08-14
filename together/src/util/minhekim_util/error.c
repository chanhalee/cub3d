/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhekim <minhekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 01:34:32 by minhekim          #+#    #+#             */
/*   Updated: 2022/08/15 01:36:57 by minhekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	put_error(char *s)
{
	if (s == NULL)
		return ;
	write(2, s, ft_strlen(s));
	return ;
}

int	arg_error(void)
{
	put_error("Error: wrong number of arguments\n");
	return (1);
}

int	img_error(void)
{
	put_error("Error: failed to open image files\n");
	return (1);
}

int	parse_error(int flag, t_map *map)
{
	put_error("Error: ");
	if (flag == 1)
		put_error("filename is not a valid .cub format\n");
	else if (flag == 2)
		put_error("failed to open input file\n");
	else if (flag == 3)
		put_error("failed to find valid texture/rgb in input file\n");
	else if (flag == 4)
		put_error("failed to read map into buffer\n");
	else if (flag == 5)
		put_error("map conversion could not be completed\n");
	else if (flag == 6)
		put_error("map did not pass validity check\n");
	free(map);
	return (1);
}
