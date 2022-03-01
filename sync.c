/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:31:03 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/28 16:25:42 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void   check_sync_rr(t_moves *menu)
{
    if (menu->ra_opti > 0 && menu->rb_opti > 0)
    while (menu->ra_opti != 0 || menu->rb_opti !=0 )
    {
            menu->ra_opti--;
            menu->rb_opti--;
            menu->rr++;
            if (menu->ra_opti == 0 || menu->rb_opti == 0)
            {
                break;
            }
    }
}
    
void check_sync_rrr(t_moves *menu)   
{
    if (menu->rra_opti > 0 && menu->rrb_opti > 0)
    {
        while (menu->rra_opti || menu->rrb_opti)
        {
            menu->rra_opti--;
            menu->rrb_opti--;
            menu->rrr++;
            if (menu->rra_opti == 0 || menu->rrb_opti == 0)
                break;
        }
    }
}