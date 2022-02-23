/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   departure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:42:53 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/23 20:21:44 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int control_visa(t_toolbox *box)
{
    int valid_visa;
    
    valid_visa= 0;
    while(valid_visa < box->max)
    {
        if (box->list_a->content == box->lis[valid_visa])
            return(0);
        valid_visa++;
    }
    return(1);
}

t_toolbox boarding_gate(t_toolbox *box)
{
    int passenger;
    int scanning;
    passenger = 0;
    scanning = box->count;
    while(passenger <= scanning)
    {
        if(control_visa(box) == 0)
            ft_rotate_a(box);
        else
        {
            ft_push_b(box);
        }
        passenger++;
    }
    box->count -= box->max;
    return(*box);
}
                 
