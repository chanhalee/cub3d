// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   mlx_img_init.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/08/09 20:11:54 by chanhale          #+#    #+#             */
// /*   Updated: 2022/08/12 13:11:10 by chanhale         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../../header/cub3d.h"

// int	mlx_img_init(t_mlx *mlx)
// {
// 	char	*temp;
// 	int	img_w;
// 	int	img_h;

// 	temp = (char *)mlx->e_img;
// 	mlx->e_img = mlx_xpm_file_to_image(mlx->mlx, temp, &img_w, &img_h);
// 	if (temp != NULL)
// 		free (temp);
// 	temp = (char *)mlx->w_img;
// 	mlx->w_img = mlx_xpm_file_to_image(mlx->mlx, temp, &img_w, &img_h);
// 	if (temp != NULL)
// 		free (temp);
// 	temp = (char *)mlx->s_img;
// 	mlx->s_img = mlx_xpm_file_to_image(mlx->mlx, temp, &img_w, &img_h);
// 	if (temp != NULL)
// 		free (temp);
// 	temp = (char *)mlx->n_img;
// 	mlx->n_img = mlx_xpm_file_to_image(mlx->mlx, temp, &img_w, &img_h);
// 	if (temp != NULL)
// 		free (temp);
// 	if (mlx->e_img && mlx->w_img && mlx->s_img && mlx->n_img)
// 		return (0);
// 	return (1);
// }