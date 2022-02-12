/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:07:02 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/12 12:07:58 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_list_int  *ft_list_init(t_toolbox *box, char **av)
{
    int i;
    i = 0;
    box->list_a = NULL;
    while(av[i])
        ft_lstadd_back_int(&box->list_a, ft_lstnew_int(ft_atol(av[i++])));
    return(&(*box->list_a));
}

t_toolbox   ft_toolbox_init(t_toolbox *box, int ac, char **av)
{
    box->nb = ac - 1;
    box->index = ft_index_values(ac, av);
    box->list_a = ft_list_init(box, av);
    box->list_b = NULL;
    return(*box);
}


int main(int ac, char **av)
{
    
    t_toolbox box;                            //t_list_int  *list;
    
    if (ac <= 1)                              //je check d'abord les erreurs 
        return(0);
    if (ft_check_error(av, ac) == 1)
		return (write(2, "Error\n", 6), 1);
    ft_toolbox_init(&box, ac, av);            // j'initialise tous mes outils
	print_list(box.list_a);
    /*tab = ft_index_values(av, ac);
    i = 0;
    while(tab[i])
    {
        printf("index: %d\n", tab[i]);
        i++;
    }*/
    return(0);
}