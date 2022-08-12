/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:38:41 by minhekim          #+#    #+#             */
/*   Updated: 2022/08/12 13:12:38 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	mem_size;
	void			*ret;

	mem_size = nmemb * size;
	ret = malloc(mem_size);
	if (!ret)
		return ((void *)0);
	ft_memset(ret, 0, mem_size);
	return (ret);
}
