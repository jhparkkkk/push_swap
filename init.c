/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:11:09 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/04 17:38:28 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	ft_check_values(int *tab, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (tab[i] == tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	*ft_tab_values(int ac, char **av)
{
	int	i;
	int	j;
	int	*tab_values;

	i = 1;
	j = 0;
	tab_values = ft_calloc(ac, sizeof(int));
	while (av[i] && i < ac)
		tab_values[j++] = ft_atol(av[i++]);
	if (ft_check_values(tab_values, ac) == 1)
	{
		printf("!!!!!!!!!!!!!!!!!!!\n");
		free(tab_values);
		write(2, "Error\n", 6);
		exit(1);
	}
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
	box->list_a = ft_lst_init(box);
	if (ac == 5 || ac > 6)
		box->lis = ft_tab_lis(box);
	box->list_b = NULL;
	return (*box);
}
