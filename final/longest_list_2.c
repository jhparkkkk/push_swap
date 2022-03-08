/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_list_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:57:18 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/08 23:37:00 by jeepark          ###   ########.fr       */
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

int	ft_check_sorted(int *tab, int ac)
{
	int i;
	int j;

	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (tab[i] > tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
