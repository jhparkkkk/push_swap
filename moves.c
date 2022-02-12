/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:18:53 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/12 15:09:16 by jeepark          ###   ########.fr       */
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
    if (ft_lstlen(box->list_a) > 1)
    {
        
    }
}