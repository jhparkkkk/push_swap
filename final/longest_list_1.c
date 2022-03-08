/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_list_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:07:08 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/08 12:04:30 by jeepark          ###   ########.fr       */
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

static void	ft_find_lis_len2(t_toolbox **box, int *ix, int *map, int *lis_len)
{
	int	i;
	int	j;

	i = ix[0];
	j = ix[1];
	if ((*box)->values[j] < (*box)->values[i] && lis_len[i] <= lis_len[j] + 1)
	{
		(lis_len[i]) = (lis_len[j]) + 1;
		map[i] = j;
		if ((*box)->max < lis_len[i])
		{
			(*box)->max = lis_len[i];
			(*box)->max_pos = i;
		}
	}
}

int	*ft_find_lis_len(t_toolbox *box, int *lis_len)
{
	int	*map;
	int	ix[2];

	map = ft_calloc(box->count, sizeof(int));
	if (!map)
		return (free(lis_len), NULL);
	ix[0] = 0;
	while (++ix[0] < box->count)
	{
		ix[1] = -1;
		while (++ix[1] < ix[0])
			ft_find_lis_len2(&box, ix, map, lis_len);
	}
	return (map);
}

static int	*ft_find_lis_pos(t_toolbox *box, int *lis_len)
{
	int	*map;
	int	*pos;
	int	index[3];

	ft_init_lis_pos(&map, &pos, lis_len, box);
	if (!pos)
		return (NULL);
	pos[0] = box->max_pos;
	index[2] = 1;
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
	box->lis = ft_calloc(box->max, sizeof(int));
	if (!box->lis)
		return (free(lis_len), free(pos), NULL);
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
