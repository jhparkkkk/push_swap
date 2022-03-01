/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:42:36 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/01 19:56:54 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	spy_content(t_toolbox *box, t_moves *menu)
{
	t_list_int	*spy;
	int		spy_pos;
	int result = 0;
	spy = box->list_b;
	spy_pos = menu->rb;
	while (spy->next && spy_pos > 0)
	{
		result = spy->content;
		spy = spy->next;
		spy_pos--;
	}
	result = spy->content;
	return (result);
}

int	find_target(t_toolbox *box, t_moves *menu, int i)
{
	t_list_int	*target;
	int		spy;
	int		scanning;
	int		distance;

	if (box->list_b == NULL)
		return (0);
	target = box->list_a;
	spy = spy_content(box, menu);
	scanning = 0;
	distance = ft_find_max(box) - spy;
	while (target)
	{
		if (spy > ft_find_max(box) && target->content == ft_find_min(box))
			return (i);
		if (target->content > spy && target->content - spy <= distance)
		{
			distance = target->content - spy;
			scanning = i;
		}
		target = target->next;
        i++;
	}
	return (scanning);
}
