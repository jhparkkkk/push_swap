/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:11:09 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/02 13:49:34 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	*ft_tab_values(int ac, char **av)
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

static t_list_int	*ft_lst_init(t_toolbox *box)
{
	int	i;

	i = 0;
	box->list_a = NULL;
	while (i < box->count)
		ft_lstadd_back_int(&box->list_a, ft_lstnew_int(box->values[i++]));
	return (&(*box->list_a));
}

void	ft_list_free(t_toolbox *box)
{
	t_list_int	*tmp;
	t_list_int	*bin;

	tmp = box->list_a;
	while (tmp)
	{
		bin = tmp->next;
		free(tmp);
		tmp = bin;
	}
}

t_toolbox	ft_toolbox_init(t_toolbox *box, int ac, char **av)
{
	box->count = ac - 1;
	box->max = 0;
	box->max_pos = 0;
	box->values = ft_tab_values(ac, av);
	if (ac >= 5)
		box->lis = ft_tab_lis(box);
	box->list_a = ft_lst_init(box);
	box->list_b = NULL;
	return (*box);
}
