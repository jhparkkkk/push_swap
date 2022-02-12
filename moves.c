/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:18:53 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/12 20:06:47 by jeepark          ###   ########.fr       */
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
        tmp = tmp->next;
        i++;
    }
    i++;
    return i;  
}

void    ft_swap_a(t_toolbox *box)
{
    t_list_int *tmp;
    int i;

    i = 0;

    tmp = NULL;
    
    if (ft_lstlen(box) > 1)
    {
        tmp = box->list_a;    
        printf("TMP: %d\n", tmp->content);   
        printf("34 YOU HERE ?: %d\n", box->list_a->content);
        box->list_a = box->list_a->next;
        tmp->next = tmp;
        printf("WHERETF AM I ?: %d\n", box->list_a->content);
        //printf("AND HOW ABOUT NOW ?: %d\n", box->list_a->content);
        //box->list_a = box->list_a->next;
        
        //box->list_a = box->list_a->next;
        //printf("1s POS: %d\n", box->list_a->content);
        
        printf("SWAP\n");
        //print_list(box->list_a);
        //printf("1s POS after swap: %d\n", box->list_a->content);
        //box->list_a = box->list_a->next;
        //box->list_a = tmp;
        //printf("1s POS after swap: %d\n", box->list_a->content);
        //printf("2nd POS: %d\n", box->list_a->content);
        //box->list_a->next = tmp;
    }
    free(tmp);
}