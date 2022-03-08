/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:40:52 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/04 18:59:43 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <time.h>

static t_moves	menu_settings(t_toolbox *box, t_moves *menu, int i)
{
	menu->rb = i;
	menu->ra = find_target(box, menu, 0, 0);
	menu->rra = box->max - menu->ra;
	menu->rrb = box->count - menu->rb;
	menu->ra_opti = menu->ra;
	menu->rb_opti = menu->rb;
	menu->rra_opti = menu->rra;
	menu->rrb_opti = menu->rrb;
	menu->rr = 0;
	menu->rrr = 0;
	menu->price = 0;
	menu->cost = 0;
	menu->execution = 0;
	return (*menu);
}

static void	execution(t_toolbox *box, t_moves *best)
{
	if (best->execution == 0)
		ft_ra_rb(box, best);
	if (best->execution == 1)
		ft_rra_rrb(box, best);
	if (best->execution == 2)
		ft_ra_rrb(box, best);
	if (best->execution == 3)
		ft_rra_rb(box, best);
	ft_push_a(box);
	box->count--;
	box->max++;
}

static void	simulation(t_moves *menu)
{
	int	price[4];
	int	i;
	int	cost;

	i = 0;
	cost = 0;
	price[0] = menu->ra_opti + menu->rb_opti + menu->rr;
	price[1] = menu->rra_opti + menu->rrb_opti + menu->rrr;
	price[2] = menu->ra + menu->rrb;
	price[3] = menu->rra + menu->rb;
	cost = price[0];
	while (i < 4)
	{
		if (price[i] <= cost)
		{
			menu->cost = price[i];
			menu->execution = i;
		}
		i++;
	}
}

void	meta_simulation(t_toolbox *box)
{
	t_moves	menu;
	t_moves	best;
	int		i;

	i = 0;
	menu = menu_settings(box, &menu, i);
	check_sync_rr(&menu);
	check_sync_rrr(&menu);
	simulation(&menu);
	ft_memcpy(&best, &menu, sizeof(t_moves));
	i++;
	while (i < box->count)
	{
		menu = menu_settings(box, &menu, i);
		check_sync_rr(&menu);
		check_sync_rrr(&menu);
		simulation(&menu);
		if (menu.cost < best.cost)
			best = menu;
		i++;
	}
	execution(box, &best);
	menu = (t_moves){};
}
