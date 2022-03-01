/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:11:09 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/01 17:12:40 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	*ft_tab_values(int ac, char **av)
{
	int	i;
	int	j;
	int	*tab_values;

	i = 1;
	j = 0;
	tab_values = ft_calloc(ac - 1, sizeof(int));
	while (av[i] && i < ac)
		tab_values[j++] = ft_atol(av[i++]);
	return (tab_values);
}

t_list_int	*ft_lst_init(t_toolbox *box)
{
	int	i;

	i = 0;
	box->list_a = NULL;
	while (i < box->count)
		ft_lstadd_back_int(&box->list_a, ft_lstnew_int(box->values[i++]));
	return (&(*box->list_a));
}

t_toolbox	ft_toolbox_init(t_toolbox *box, int ac, char **av)
{
	box->count = ac - 1;
	box->max = 0;
	box->max_pos = 0;
	box->values = ft_tab_values(ac, av);
	if (ac >= 5)
		box->lis = ft_tab_lis(box);
	box->list_a = ft_lst_init(box); // ft_lstclear(box->list_a)
	box->list_b = NULL;
	return (*box);
}
void	ft_toolbox_free(t_toolbox *box)
{
	t_list_int	*head;
	head = box->list_a;
	t_list_int	*temp;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
