/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   departure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:42:53 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/04 17:49:59 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	control_visa(t_toolbox *box)
{
	int	valid_visa;

	valid_visa = 0;
	while (valid_visa < box->max)
	{
		if (box->list_a->content == box->lis[valid_visa])
			return (0);
		valid_visa++;
	}
	return (1);
}

/*int check_baggage(t_toolbox *box)
{
	t_list_int	*tmp;

	if (box->list_a == NULL)
		return (0);
	tmp = box->list_a;
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}*/

t_toolbox	boarding_gate(t_toolbox *box)
{
	int	passenger;
	int	scanning;
	int i;
	passenger = 0;
	scanning = box->count;
	i = 0;
	while (passenger <= scanning)
	{
		if (control_visa(box) == 0)
		{
			ft_rotate_a(box);
			write(1, "ra\n", 3);
		}
		else
		{
			ft_push_b(box);
		}
		passenger++;
	}
	box->count -= box->max;
	return (*box);
}
