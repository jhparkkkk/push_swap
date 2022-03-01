/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:07:02 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/01 20:05:37 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	int		roulette;
	t_toolbox	box;

	if (ft_check_error(av, ac) == 1)
		write(STDERR_FILENO, "Error\n", 6);
	ft_toolbox_init(&box, ac, av);
	if (ac <= 2)
		return(0);
	if(ft_check_sorted_list_a(&box) == 0)
		return (0);
	if (ac <= 4)
		ft_sort_three(&box);
	if (ac == 6)
		ft_sort_five(&box);
	// print_list(box.list_a);
	
	if (ac > 6 || ac == 5)
	{
		boarding_gate(&box);
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
	//print_list(box.list_a);
	free(box.values);
	ft_toolbox_free(&box);
	
	return (0);
}
