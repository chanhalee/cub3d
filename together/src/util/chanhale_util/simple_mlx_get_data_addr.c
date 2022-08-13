/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_mlx_get_data_addr.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:04:06 by chanhale          #+#    #+#             */
/*   Updated: 2022/08/13 13:08:33 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

unsigned int	*simple_mlx_get_data_addr(void *img_ptr)
{
	unsigned int	*ret;
	int				a;
	int				b;
	int				c;

	if (img_ptr == NULL)
		return (NULL);
	ret = (unsigned int *)mlx_get_data_addr(img_ptr, &a, &b, &c);
	return (ret);
}
