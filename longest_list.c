/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:07:08 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/01 19:41:31 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	*ft_tab_lis_len(t_toolbox *box)
{
	int	i;
	int	*lis_len;

	lis_len = ft_calloc(box->count, sizeof(int));
	i = 0;
	while (i < box->count)
	{
		lis_len[i] = 1;
		i++;
	}
	return (lis_len);
}

static int	*ft_find_lis_len(t_toolbox *box, int *lis_len)
{
	int	*map;
	int	i;
	int	j;

	map = ft_calloc(box->count, sizeof(int));
	i = 1;
	while (i < box->count)
	{
		j = 0;
		while (j < i)
		{
			if (box->values[j] < box->values[i] && lis_len[i] <= lis_len[j] + 1)
			{
				lis_len[i] = lis_len[j] + 1;
				map[i] = j;
				if (box->max < lis_len[i])
				{
					box->max = lis_len[i];
					box->max_pos = i;
				}
			}
			j++;
		}
		i++;
	}
	return (map);
}

static int	*ft_find_lis_pos(t_toolbox *box, int *lis_len)
{
	int	*map;
	int *pos;
	int	i;
	int	j;
	int	k;

	k = 1;
	map = ft_find_lis_len(box, lis_len);
	pos = ft_calloc(box->max, sizeof(int));
	if (!pos)
		return 0;
	i = box->max_pos;
	j = box->max_pos;
	pos[0] = i;
	while (i >= 0)
	{
		while (j >= 0)
		{
			if (map[i] == j && k < box->max)
			{
				i = j;
				pos[k] = j;
				k++;
			}
			j--;
		}
		i--;
	}
	i = 0;
	while(i < box->max)
	{
		// printf("POS[%d] = %d\n", i, pos[i]);
		i++;
	}
	free(map);
	return (pos);
}

int	*ft_tab_lis(t_toolbox *box)
{
	int *pos;
	int	*lis_len;
	int	i;
	int	j;
	int	k;

	lis_len = ft_tab_lis_len(box);
	pos = ft_find_lis_pos(box, lis_len);
	box->lis = ft_calloc(box->max, sizeof(int));
	i = 0;
	k = 0;
	while (i < box->max)
	{
		j = 0;
		while (j <= box->max_pos)
		{
			if (pos[i] == j)
				box->lis[k++] = box->values[j];
			j++;
		}
		i++;
	}
	i = 0;
	while(i < box->max)
	{
		// printf("LIS[%d] = %d\n", i, box->lis[i]);
		i++;
	}
	free(pos);
	free(lis_len);
	return (&(*box->lis));
}
