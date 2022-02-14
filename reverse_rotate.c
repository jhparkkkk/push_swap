/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:24:23 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/14 15:26:21 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void    ft_reverse_rotate_a(t_toolbox *box)
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

void    ft_reverse_rotate_b(t_toolbox *box)
{
    t_list_int *tmp;
    t_list_int *bin;

    tmp = NULL;
    bin = NULL;
    if (box->list_b->next == NULL)
        return ;
    tmp = box->list_b;
    bin = box->list_b;
    while(tmp->next != NULL)
        tmp = tmp->next;
    ft_lstadd_front_int(&box->list_b, ft_lstnew_int(tmp->content));
    while(bin->next != NULL && bin->next->content != tmp->content)
        bin = bin->next;
    free(bin->next);
    bin->next = NULL;
}

void    ft_reverse_rotate_rr(t_toolbox *box)
{
    ft_reverse_rotate_a(box);
    ft_reverse_rotate_b(box);
}