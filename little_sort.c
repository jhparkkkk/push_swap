/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:52:54 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/28 18:52:56 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static t_toolbox	ft_sort_two(t_toolbox *box)
{
	if (box->list_a->content > box->list_a->next->content)
	{
		ft_swap_a(box);
		exit (0);
	}
	exit (0);
}

t_toolbox	ft_sort_three(t_toolbox *box)
{
	int	min;
	int	max;

	if (box->count == 2)
		ft_sort_two(box);
	min = ft_find_min(box);
	max = ft_find_max(box);
	while (box->list_a->next->next->content != max)
	{
		ft_reverse_rotate_a(box);
		write(1, "rra\n", 4);
	}
	if (box->list_a->next->content == min)
		ft_swap_a(box);
	return (*box);
}

t_toolbox	ft_sort_five(t_toolbox *box)
{
	int	min;

	min = find_min_pos(box);
	if (min == 4)
	{
		ft_reverse_rotate_a(box);
		write(1, "rra\n", 4);
	}
	else
	{
		while (min > 0)
		{
			ft_rotate_a(box);
			write(1, "ra\n", 3);
			min--;
		}
	}
	ft_push_b(box);
	min = find_min_pos(box);
	while (min > 0)
	{
		ft_rotate_a(box);
		write(1, "ra\n", 3);
		min--;
	}
	ft_push_b(box);
	ft_sort_three(box);
	ft_push_a(box);
	ft_push_a(box);
	return (*box);
}
