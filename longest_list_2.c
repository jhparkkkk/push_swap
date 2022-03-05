/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_list_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:57:18 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/05 22:16:29 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_lis_pos(int **map, int **pos, int *lis_len, t_toolbox *box)
{
	*map = ft_find_lis_len(box, lis_len);
	*pos = ft_calloc(box->max, sizeof(int));
	if (!*pos)
		return (free(lis_len), free(map));
}
