/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:42:36 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/22 11:40:23 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int find_target(t_toolbox *box)
{
    t_list_int *spy;
    t_list_int *target;
    int scanning;
    
    target = box->list_a;
    spy = box->list_b;
    scanning = 0;
    /*printf("SPY = %d\n", spy->content);
    printf("TARGET UP = %d\n", target->content);
    printf("TARGET DOWN = %d\n", target->next->content);*/
    while(target)
    {   
        scanning++;
        if(spy->content > target->content && spy->content < target->next->content)
            return(scanning);
        target = target->next;
         
    }
    return(0);
}

