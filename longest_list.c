/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:07:08 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/04 17:46:29 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	*ft_tab_lis_len(t_toolbox *box)
{
	int	i;
	int	*lis_len;

	lis_len = ft_calloc(box->count, sizeof(int));
	if (!lis_len)
		return (0);
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
	i = 0;
	while (++i < box->count)
	{
		j = -1;
		while (++j < i)
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
		}
	}
	return (map);
}

static int	*ft_find_lis_pos(t_toolbox *box, int *lis_len)
{
	int	*map;
	int	*pos;
	int	index[3];

	index[2] = 1;
	map = ft_find_lis_len(box, lis_len);
	pos = ft_calloc(box->max, sizeof(int));
	pos[0] = box->max_pos;
	index[0] = box->max_pos + 1;
	index[1] = box->max_pos + 1;
	while (--index[0] >= 0)
	{
		while (--index[1] >= 0)
		{
			if (map[index[0]] == index[1] && index[2] < box->max)
			{
				index[0] = index[1];
				pos[index[2]++] = index[1];
			}
		}
	}
	if (ft_memcmp(map, pos, box->max_pos) == 0)
		box->max = 1;
	return (free(map), pos);
}

int	*ft_tab_lis(t_toolbox *box)
{
	int	*pos;
	int	*lis_len;
	int	index[3];

	lis_len = ft_tab_lis_len(box);
	pos = ft_find_lis_pos(box, lis_len);
	if (pos[0] == 0 && pos[1] == 0)
		return (NULL);
	box->lis = ft_calloc(box->max, sizeof(int));
	index[0] = 0;
	index[2] = 0;
	while (index[0] < box->max)
	{
		index[1] = 0;
		while (index[1] <= box->max_pos)
		{
			if (pos[index[0]] == index[1])
				box->lis[index[2]++] = box->values[index[1]];
			index[1]++;
		}
		index[0]++;
	}
	return (free(pos), free(lis_len), &(*box->lis));
}
