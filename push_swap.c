/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:07:02 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/04 14:37:09 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <time.h>

/*void	ft_strictly_decreasing_values(t_toolbox *box) // ca ne marche pas
{
	while(--box->count > 0)
	{
		ft_rotate_a(box);
		write(1, "ra\n", 3);
	}
	print_list(box->list_a);
	free(box->values);
	ft_list_free(box);
}*/

int	main(int ac, char **av)
{
	int			i = 0;
	t_toolbox	box;

	if (ft_check_error(av, ac) == 1)
		return (write(STDERR_FILENO, "Error\n", 6), 0);
	ft_toolbox_init(&box, ac, av);
	if (ac <= 2)
		return (free(box.values), ft_list_free(&box), 0);
	if (ft_check_sorted_list_a(&box) == 0)
		return (free(box.values), ft_list_free(&box), 0);
	
	if (ac <= 4)
		ft_sort_three(&box);
	if (ac == 6)
		ft_sort_five(&box);
	i= 0;
	if (ac > 6 || ac == 5)
	{
		boarding_gate(&box);
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
