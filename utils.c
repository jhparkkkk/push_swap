/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:43:22 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/18 15:04:44 by jeepark          ###   ########.fr       */
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

int		ft_find_min(t_toolbox *box)
{
	int	min;
    int i;
    t_list_int *tmp;
    i = 0;
    tmp = box->list_a;
    min = tmp->content;
	while (tmp->next)
	{
        if (tmp->content < min)
			min = tmp->content;
        tmp = tmp->next;
    }
	if (tmp->content < min)
			min = tmp->content;
	return (min);
}

int		ft_find_max(t_toolbox *box)
{
	int	max;
    int i;
    t_list_int *tmp;
    i = 0;
    tmp = box->list_a;
    max = tmp->content;
	while (tmp->next)
	{
        if (tmp->content > max)
			max = tmp->content;
        tmp = tmp->next;
    }
	if (tmp->content > max)
			max = tmp->content;  
	return (max);
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