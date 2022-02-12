/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:34:21 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/12 12:46:41 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstprint(t_list_int *list)
{
    t_list_int  *tmp;
    tmp = list;
   	while (tmp->next != NULL)
    {
        printf("%d\n", tmp->content);
        tmp = tmp->next;
    }
    printf("%d\n", tmp->content);
}