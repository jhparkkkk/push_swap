/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   departure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:42:53 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/04 14:36:48 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

void	ft_strictly_decreasing_values(t_toolbox *box, int scanning)
{
	while(--scanning > 0)
	{	
		ft_reverse_rotate_a(box);
		write(1, "rra\n", 4);
		ft_push_b(box);
	}
}

t_toolbox	boarding_gate(t_toolbox *box)
{
	int	passenger;
	int	scanning;

	passenger = 0;
	scanning = box->count;
	if (!box->lis)
		ft_strictly_decreasing_values(box, scanning);
	else 
	{
		while (passenger <= scanning)
		{
			if (control_visa(box) == 0)
			{
				ft_rotate_a(box);
				write(1, "ra\n", 3);
			}
			else
				ft_push_b(box);
		}
		passenger++;
	}
	box->count -= box->max;
	return (*box);
}
