/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrival.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:12:46 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/06 20:42:00 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	fasten_your_seatbelt(t_toolbox *box)
{
	int	len;
	int	distance;

	len = ft_lstlen(box->list_a);
	distance = find_min_pos(box);
	if (distance < len / 2)
	{
		while (distance != 0)
		{
			ft_rotate_a(box);
			write(1, "ra\n", 3);
			distance--;
		}
	}
	if (distance >= len / 2)
	{
		while (distance != len)
		{
			ft_reverse_rotate_a(box);
			write(1, "rra\n", 4);
			distance++;
		}
	}
}
