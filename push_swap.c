/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:07:02 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/02 15:23:08 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	int			roulette;
	t_toolbox	box;
	int i = 0;
	if (ft_check_error(av, ac) == 1)
		return(write(STDERR_FILENO, "Error\n", 6), 0);
	ft_toolbox_init(&box, ac, av);
	while( i < box.max)
	{
		printf("LIS[%d] = %d\n", i, box.lis[i]);
		i++;
	}
	printf("\nHE HO\n");
	print_list(box.list_a);
	if (ac <= 2)
		return (free(box.values), ft_list_free(&box), 0);
	if (ft_check_sorted_list_a(&box) == 0)
		return(free(box.values), 0);
	if (ac <= 4)
		ft_sort_three(&box);
	if (ac == 6)
		ft_sort_five(&box);
	if (ac > 6 || ac == 5)
	{
		boarding_gate(&box);
		printf("\nHE HO\n");
		print_list(box.list_a);
		roulette = box.count;
		while (roulette >= 0)
		{
			meta_simulation(&box);
			roulette--;
		}
		if (box.list_a->content != ft_find_min(&box))
			fasten_your_seatbelt(&box);
		free(box.lis);
	}
	print_list(box.list_a);
	return (free(box.values), ft_list_free(&box), 0);
}
