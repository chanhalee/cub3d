/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:20:37 by minhekim          #+#    #+#             */
/*   Updated: 2022/08/12 13:12:44 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*mem;
	unsigned char	byte;
	unsigned int	i;

	mem = (unsigned char *)dest;
	byte = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		*mem = byte;
		mem++;
		i++;
	}
	return (dest);
}
