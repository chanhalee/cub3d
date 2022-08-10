/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:11:54 by chanhale          #+#    #+#             */
/*   Updated: 2022/08/10 14:12:02 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/RayCasting.h"

void	 mlx_img_init(t_mlx *mlx)
{
	char	*temp;

	temp = (char *)mlx->e_img;
	mlx->e_img = mlx_xpm_file_to_image()
}