/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:07:02 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/28 20:09:20 by jeepark          ###   ########.fr       */
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
	if (ac > 6 || ac == 5)
		boarding_gate(&box);
	roulette = box.count;
	while (roulette >= 0)
	{
		meta_simulation(&box);
		roulette--;
	}
	if (box.list_a->content != 0)
		fasten_your_seatbelt(&box);
	return (0);
}
