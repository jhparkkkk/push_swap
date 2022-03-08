/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   departure_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:42:53 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/08 23:36:04 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_tab_sort2(t_toolbox *box, int *copy)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < box->count)
	{
		j = i + 1;
		while (j < box->count)
		{
			if (copy[i] > copy[j])
			{
				tmp = copy[i];
				copy[i] = copy[j];
				copy[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (copy);
}

static int	*ft_tab_sort(t_toolbox *box)
{
	int	*copy;

	copy = box->values;
	if (!copy)
		return (0);
	copy = ft_tab_sort2(box, copy);
	return (copy);
}

int	find_mediane(t_toolbox *box)
{
	int	mediane;
	int	*sorted_tab;

	mediane = (box->count) / 2;
	sorted_tab = ft_tab_sort(box);
	if (!sorted_tab)
	{
		free(box->values);
		free(box->lis);
		ft_list_free(box);
		exit (1);
	}
	mediane = sorted_tab[mediane];
	return (mediane);
}
