/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:22:40 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/28 16:35:32 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_ra_rb(t_toolbox *box, t_moves *best)
{
	if (best->rr)
	{
		ft_rotate_rr(box);
		write(1, "rr\n", 3);
		best->rr--;
		ft_ra_rb(box, best);
	}
	if (best->ra_opti)
	{
		ft_rotate_a(box);
		write(1, "ra\n", 3);
		best->ra_opti--;
		ft_ra_rb(box, best);
	}
	if (best->rb_opti)
	{
		ft_rotate_b(box);
		write(1, "rb\n", 3);
		best->rb_opti--;
		ft_ra_rb(box, best);
	}
}

void	ft_rra_rrb(t_toolbox *box, t_moves *best)
{
	if (best->rrr)
	{
		ft_reverse_rotate_rr(box);
		write(1, "rrr\n", 4);
		best->rrr--;
		ft_rra_rrb(box, best);
	}
	if (best->rra_opti)
	{
		ft_reverse_rotate_a(box);
		write(1, "rra\n", 4);
		best->rra_opti--;
		ft_rra_rrb(box, best);
	}
	if (best->rrb_opti)
	{
		ft_reverse_rotate_b(box);
		write(1, "rrb\n", 4);
		best->rrb_opti--;
		ft_rra_rrb(box, best);
	}
}

void	ft_ra_rrb(t_toolbox *box, t_moves *best)
{
	if (best->ra)
	{
		ft_rotate_a(box);
		write(1, "ra\n", 3);
		best->ra--;
		ft_ra_rrb(box, best);
	}
	if (best->rrb)
	{
		ft_reverse_rotate_b(box);
		write(1, "rrb\n", 4);
		best->rrb--;
		ft_ra_rrb(box, best);
	}
}

void	ft_rra_rb(t_toolbox *box, t_moves *best)
{
	if (best->rra)
	{
		ft_reverse_rotate_a(box);
		write(1, "rra\n", 4);
		best->rra--;
		ft_rra_rb(box, best);
	}
	if (best->rb)
	{
		ft_rotate_b(box);
		write(1, "rb\n", 3);
		best->rb--;
		ft_rra_rb(box, best);
	}
}
