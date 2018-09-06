/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 10:49:35 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 10:55:50 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_general(t_general *general)
{
	general->data = NULL;
	general->parsed_data = NULL;
	general->mlx_ptr = NULL;
	general->win_ptr = NULL;
	general->step = STEP_BASE;
}
