/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:43:22 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/10 13:43:38 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void print_list(t_list_int *list)
{
    t_list_int  *tmp = list;
   	while (tmp->next != NULL)
    {
        printf("%d\n", tmp->content);
        tmp = tmp->next;
    }
    printf("%d\n", tmp->content);
}