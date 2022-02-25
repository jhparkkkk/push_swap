/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrival.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:12:46 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/25 18:44:32 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void fasten_your_seatbelt(t_toolbox *box)
{
    t_list_int *tmp;
    tmp = box->list_a;
    while(tmp->content != 0)
    {
        ft_reverse_rotate_a(box);
        write(1, "rra\n", 4);
        compteur++;
        tmp = box->list_a;
    }
}