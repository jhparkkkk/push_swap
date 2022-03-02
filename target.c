/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:42:36 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/02 20:31:02 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <time.h>
static int	spy_content(t_toolbox *box, t_moves *menu)
{
	t_list_int	*spy;
	int			spy_pos;
	int			result;

	spy = box->list_b;
	spy_pos = menu->rb;
	result = 0;
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
	clock_t start, end;
    double cpu_time_used;
	t_list_int	*target;
	int			spy;
	int			scanning;
	int			distance;

	if (box->list_b == NULL)
		return (0);
	start = clock();
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
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTARGET = %f\n", cpu_time_used);
	return (scanning);
}
