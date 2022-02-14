/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:01:20 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/14 15:15:19 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void    ft_swap_a(t_toolbox *box)
{
    t_list_int *tmp;
    
    tmp = NULL;
    if(box->list_a == NULL)
        return ;
    if (box->list_a != NULL || box->list_a->next != NULL)
    {
        tmp = box->list_a;
        box->list_a = box->list_a->next;
        tmp->next = box->list_a->next; 
        box->list_a->next = tmp;
    }
    return ;
}

void    ft_swap_b(t_toolbox *box)
{
    t_list_int *tmp;
    
    tmp = NULL;
    if(box->list_b == NULL)
        return ;
    if (box->list_b != NULL || box->list_b->next != NULL)
    {
        tmp = box->list_b;
        box->list_b = box->list_b->next;
        tmp->next = box->list_b->next; 
        box->list_b->next = tmp;
    }
    return ;
}

void    ft_swap_ss(t_toolbox *box)
{
    ft_swap_a(box);
    ft_swap_b(box);
}