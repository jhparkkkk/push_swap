/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:07:02 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/24 00:07:18 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_list_int  *ft_list_init_tab(t_toolbox *box)
{
    int i;
    i = 0;
    box->list_a = NULL;
    while(i < box->count)
        ft_lstadd_back_int(&box->list_a, ft_lstnew_int(box->index[i++]));
    return(&(*box->list_a));
}

t_toolbox   ft_toolbox_init(t_toolbox *box, int ac, char **av)
{
    box->count = ac - 1;
	box->max = 0;
	box->max_pos = 0;
	box->values = ft_index_tab_init(ac, av);
    box->index = ft_index_values(ac, av);
	box->lis = ft_lis_keeper(box);
    box->list_a = ft_list_init_tab(box);
    box->list_b = NULL;
	box->lim_max = ft_find_max(box);
    return(*box);
}


int main(int ac, char **av)
{
    
    t_toolbox box;
	t_moves menu;                      
	int roulette;
    if (ac <= 1)                              
        return(0);   
    if (ft_check_error(av, ac) == 1)
		return (write(2, "Error\n", 6), 1);
    if (ac == 2)
    {
        write(1, av[1], ft_strlen(av[1]));
        return(0);
    }
	ft_toolbox_init(&box, ac, av);
	if (ac <= 4)
        ft_sort_three(&box);
	if (ac > 5)
		boarding_gate(&box);
	roulette = box.count;
	while(roulette >= 0)
	{
		simulation(&box, &menu);
		execution(&box, &menu);
		roulette--;
	}
	if (box.list_a->content != 0)
		fasten_your_seatbelt(&box);
	print_list(box.list_a);
	print_list(box.list_b);
    return(0);
}