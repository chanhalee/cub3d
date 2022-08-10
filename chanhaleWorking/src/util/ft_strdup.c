/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:53:44 by chanhale          #+#    #+#             */
/*   Updated: 2022/08/10 14:52:36 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/RayCasting.h"

char	*ft_strdup(const char *src)
{
	int		size;
	int		local_index;
	char	*result;

	size = 0;
	while (src[size])
		size++;
	result = (char *)malloc((size + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	local_index = -1;
	while (++local_index < size)
		result[local_index] = src[local_index];
	result[local_index] = '\0';
	return (result);
}
