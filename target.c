/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:42:36 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/25 18:24:19 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int find_target(t_toolbox *box, t_moves *menu)
{
    t_list_int *spy;
    t_list_int *target;

    int scanning;
    int distance;
    int i;
    if(box->list_b == NULL)
        return(0);
    target = box->list_a;
    spy = box->list_b;
    scanning = 0;
    i = menu->rb;
    while(i > 0)
    {
        spy = spy->next;
        i--;
    }
    i = 0;
    distance = (ft_find_max(box)) - (spy->content);
    while(target)
    {
        if (spy->content > ft_find_max(box))
        {
            if (target->content == ft_find_min(box))
            {
                return(i);
            }
        }
        if(target->content > spy->content)
        {
            if (target->content - spy->content <= distance)
            {
                
                distance = target->content - spy->content;
                scanning = i;
            }
        }
        i++;
        target = target->next;
        
    }

    return(scanning);
}
