/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   departure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:26:40 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/06 22:34:02 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	control_visa(t_toolbox *box, t_list_int *tmp)
{
	int	valid_visa;

	valid_visa = 0;
	while (valid_visa < box->max)
	{
		if (tmp->content == box->lis[valid_visa])
			return (0);
		valid_visa++;
	}
	return (1);
}

void	passenger_seat(t_toolbox *box, t_list_int *tmp, int mediane)
{
	if (tmp->content < mediane)
	{
		ft_push_b(box);
		if (box->list_b)
		{
			ft_rotate_b(box);
			write (1, "rb\n", 3);
		}
	}
	else
		ft_push_b(box);
}

t_toolbox	boarding_gate(t_toolbox *box)
{
	t_list_int	*tmp;
	int			mediane;
	int			scanning;
	int			passenger;

	tmp = box->list_a;
	mediane = find_mediane(box);
	scanning = box->count;
	passenger = scanning - box->max;
	while (scanning > 0 || passenger > 0)
	{
		if (control_visa(box, tmp) == 0)
		{
			ft_rotate_a(box);
			write(1, "ra\n", 3);
		}
		else
		{
			passenger_seat(box, tmp, mediane);
			passenger--;
		}
		tmp = box->list_a;
		scanning--;
	}
	return (box->count -= box->max, *box);
}
