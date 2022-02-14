/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:43:22 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/14 21:32:41 by jeepark          ###   ########.fr       */
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

int ft_check_sorted_list_a(t_toolbox *box)
{
	t_list_int *tmp;
    
    if (box->list_a == NULL)
    {
        write(1, "list is empty\n", 14);
        return (0);
    }
	tmp = box->list_a;
	while(tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return(1);
		tmp = tmp->next;
	}
	return(0);
}

int ft_check_sorted_list_b(t_toolbox *box)
{
	t_list_int *tmp;

    if (box->list_b == NULL)
    {
        write(1, "list is empty\n", 14);
        return (0);
    }
	tmp = box->list_b;
	while(tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return(1);
		tmp = tmp->next;
	}
	return(0);
}