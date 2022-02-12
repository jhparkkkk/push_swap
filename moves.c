/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:18:53 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/12 15:45:12 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_lstlen(t_toolbox *box)
{
    t_list_int *tmp;
    int i;
    
    tmp = NULL;
    i = 0;
    tmp = box->list_a; 
    while (tmp->next != NULL)
    {   
        ++i;
        tmp = tmp->next;
    }
    i++;
    free(tmp);
    printf("LEN : %d", i);
    return i;  
}

void    ft_swap_a(t_toolbox *box)
{
    t_list_int *tmp;

    tmp = NULL;
    if (ft_lstlen(box) > 1)
    {
        tmp = box->list_a;
        box->list_a = box->list_a->next; 
        box->list_a->next = tmp; 
    }
    free(tmp);
}