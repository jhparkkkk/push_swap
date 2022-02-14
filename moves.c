/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:18:53 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/14 12:04:16 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void    ft_swap(t_toolbox *box)
{
    t_list_int *tmp;
    
    tmp = NULL;
    if (box->list_a != NULL || box->list_a->next != NULL)
    {
        tmp = box->list_a;
        box->list_a = box->list_a->next;
        tmp->next = box->list_a->next; 
        box->list_a->next = tmp;
    }
    return ;
}

void    ft_push(t_toolbox *box)
{
    t_list_int *tmp;
    
    if (box->list_a == NULL)
        return ;
    ft_lstadd_front_int(&box->list_b, ft_lstnew_int(box->list_a->content));
    tmp = box->list_a;
    box->list_a = box->list_a->next;
    free(tmp);
}

void    ft_rotate(t_toolbox *box)
{
    t_list_int *tmp;

    if (box->list_a->next == NULL)
        return ;
    ft_lstadd_back_int(&box->list_a, ft_lstnew_int(box->list_a->content));
    tmp = box->list_a;
    box->list_a = box->list_a->next;
    free(tmp);
}

void    ft_reverse_rotate(t_toolbox *box)
{
    t_list_int *tmp;
    t_list_int *bin;

    tmp = NULL;
    bin = NULL;
    if (box->list_a->next == NULL)
        return ;
    tmp = box->list_a;
    bin = box->list_a;
    while(tmp->next != NULL)
        tmp = tmp->next;
    ft_lstadd_front_int(&box->list_a, ft_lstnew_int(tmp->content));
    while(bin->next != NULL && bin->next->content != tmp->content)
        bin = bin->next;
    free(bin->next);
    bin->next = NULL;
}