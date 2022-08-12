/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:54:32 by chanhale          #+#    #+#             */
/*   Updated: 2022/08/12 13:11:11 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

double	get_distance(double from_x, double from_y, double to_x, double to_y)
{
	return (sqrt(pow((from_x - to_x), 2.0) + pow((from_y - to_y), 2.0)));
}
