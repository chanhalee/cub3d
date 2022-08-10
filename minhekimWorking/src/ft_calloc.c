/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhekim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:38:41 by minhekim          #+#    #+#             */
/*   Updated: 2022/08/10 23:46:14 by minhekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minhee.h"

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
