/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:07:02 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/22 11:51:12 by jeepark          ###   ########.fr       */
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
    return(*box);
}


int main(int ac, char **av)
{
    
    t_toolbox box;                          
	int i;
	i = 0;
	int target;
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
	print_list(box.list_a);
	while( i < box.max)
	{
		printf("LIS[%d] = %d\n", i, box.lis[i]);
		i++;
	}
	if (ac > 6)
		boarding_gate(&box);
	printf("\n------- LIST A -------\n");
	print_list(box.list_a);
	printf("\n------- LIST B -------\n");
	print_list(box.list_b);
	
	target = find_target(&box);
	printf("TARGET IS LOCATED AT = %d\n", target);
	printf("BOX COUNT = %d\n", box.count);
	printf("BOX MAX = %d\n", box.max);
    if (ac == 4)
        ft_sort_three(&box);
    if (ac == 6)
        ft_sort_five(&box);
    return(0);
}