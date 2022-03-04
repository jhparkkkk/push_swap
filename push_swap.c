/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:07:02 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/04 17:06:29 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <time.h>

int	main(int ac, char **av)
{
	int			i;
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
	return (free(box.values), ft_list_free(&box), 0);
}
