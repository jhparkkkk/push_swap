/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:52:54 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/02 18:25:48 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static t_toolbox	ft_sort_two(t_toolbox *box)
{
	if (box->list_a->content > box->list_a->next->content)
	{
		ft_swap_a(box);
	}
	return (*box);
}

t_toolbox	ft_sort_three(t_toolbox *box)
{
	int	min;
	int	max;

	if (box->count == 2)
		return (ft_sort_two(box), *box);
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

static void	ft_sort_five_spec(t_toolbox *box)
{
	ft_reverse_rotate_a(box);
	write(1, "rra\n", 4);
}

t_toolbox	ft_sort_five(t_toolbox *box)
{
	int	min;

	min = find_min_pos(box);
	if (min == 4)
		ft_sort_five_spec(box);
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
	min = find_min_pos(box) + 1;
	while (--min > 0)
	{
		ft_rotate_a(box);
		write(1, "ra\n", 3);
	}
	ft_push_b(box);
	return (ft_sort_three(box), ft_push_a(box), ft_push_a(box), *box);
}
