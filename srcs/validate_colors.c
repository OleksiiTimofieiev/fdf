/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:05:42 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/08 11:11:50 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		validate_line_with_color(char *str_for_analysis)
{
	int i;

	if (str_for_analysis[0] != '0')
		return (0);
	else if (ft_strlen(str_for_analysis) < 3 || ft_strlen(str_for_analysis) > 8)
		return (0);
	else if (str_for_analysis[1] != 'x')
		return (0);
	i = 2;
	while (str_for_analysis[i])
	{
		if (ft_isdigit(str_for_analysis[i]) || str_for_analysis[i] == 65
			|| str_for_analysis[i] == 66 || str_for_analysis[i] == 67
			|| str_for_analysis[i] == 68 || str_for_analysis[i] == 69
			|| str_for_analysis[i] == 70)
			i++;
		else
			return (0);
	}
	return (1);
}
