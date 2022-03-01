/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrival.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:12:46 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/28 16:34:08 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void fasten_your_seatbelt(t_toolbox *box)
{
    t_list_int *tmp;
    int min_pos;
    int len;
    int distance = 0;
    tmp = box->list_a;
    min_pos = ft_find_min(box);
    len = ft_lstlen(box);

    while(tmp->content != min_pos)
    {
        tmp = tmp->next;
        distance++;
    }
    tmp = box->list_a;
    if (distance < len / 2)
    {
        while(distance != 0)
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