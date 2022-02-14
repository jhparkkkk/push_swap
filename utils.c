/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:43:22 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/14 15:40:49 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

void print_list(t_list_int *list)
{
    t_list_int  *tmp = list;
    if (!list)
    {    
        printf("--EMPTY--\n");
        return ;
    }
   	while (tmp->next != NULL)
    {
        printf("%d\n", tmp->content);
        tmp = tmp->next;
    }
    printf("%d\n", tmp->content);
}