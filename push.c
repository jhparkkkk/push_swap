/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:15:38 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/28 16:35:46 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_push_a(t_toolbox *box)
{
	t_list_int	*tmp;

	if (box->list_b == NULL)
		return ;
	ft_lstadd_front_int(&box->list_a, ft_lstnew_int(box->list_b->content));
	tmp = box->list_b;
	box->list_b = box->list_b->next;
	free(tmp);
	write(1, "pa\n", 3);
}

void	ft_push_b(t_toolbox *box)
{
	t_list_int	*tmp;

	if (box->list_a == NULL)
		return ;
	ft_lstadd_front_int(&box->list_b, ft_lstnew_int(box->list_a->content));
	tmp = box->list_a;
	box->list_a = box->list_a->next;
	free(tmp);
	write(1, "pb\n", 3);
}
