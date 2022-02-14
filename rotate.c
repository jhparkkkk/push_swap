/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:21:12 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/14 20:57:12 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void    ft_rotate_a(t_toolbox *box)
{
    t_list_int *tmp;

    if (box->list_a->next == NULL)
        return ;
    ft_lstadd_back_int(&box->list_a, ft_lstnew_int(box->list_a->content));
    tmp = box->list_a;
    box->list_a = box->list_a->next;
    free(tmp);
}

void    ft_rotate_b(t_toolbox *box)
{
    t_list_int *tmp;

    if (box->list_b->next == NULL)
        return ;
    ft_lstadd_back_int(&box->list_b, ft_lstnew_int(box->list_b->content));
    tmp = box->list_b;
    box->list_b = box->list_b->next;
    free(tmp);
}

void    ft_rotate_rr(t_toolbox *box)
{
    ft_rotate_a(box);
    ft_rotate_b(box);
}