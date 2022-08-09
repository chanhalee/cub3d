/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_render_source.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:11:54 by chanhale          #+#    #+#             */
/*   Updated: 2022/08/10 00:14:17 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/RayCasting.h"

void	init_t_render_source(t_render_source *source)
{
	source->distance = 0;
	source->object = NULL;
	source->object_pos = 0;
	source->render_screen_pos = 0;
	source->ob_x = 0;
	source->ob_y = 0;
}