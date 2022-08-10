/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhekim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:20:37 by minhekim          #+#    #+#             */
/*   Updated: 2022/08/10 23:47:30 by minhekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minhee.h"

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
