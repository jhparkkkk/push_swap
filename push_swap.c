/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:07:02 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/06 19:49:54 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void print_list(t_list_int *list)
{
	t_list_int  *tmp = list;
	if (!list)
	{    
		return ;
	}
	while (tmp->next != NULL)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->content);
}

int	main(int ac, char **av)
{
	int			i;
	t_toolbox	box;

	ft_check_error(av, ac);
	ft_toolbox_init(&box, ac, av);
	
	/*i = 0;
	while(i < box.max)
	{
		printf("LIS[%d] = %d\n", i, box.lis[i]);
		i++;
	}*/
	if (ac <= 2)
		return (free(box.values), ft_list_free(&box), 0);
	if (ft_check_sorted_list_a(&box) == 0)
		return (free(box.values), ft_list_free(&box), 0);
	if (ac <= 4)
		ft_sort_three(&box);
	if (ac == 6)
		ft_sort_five(&box);
	if (ac > 6 || ac == 5)
	{
		boarding_gate(&box);
		//print_list(box.list_a);
		i = box.count + 1;
		while (--i >= 0)
			meta_simulation(&box);
		if (box.list_a->content != ft_find_min(&box))
			fasten_your_seatbelt(&box);
		free(box.lis);
	}
	//print_list(box.list_a);
	return (free(box.values), ft_list_free(&box), 0);
}
