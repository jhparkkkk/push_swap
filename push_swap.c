/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:07:02 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/11 23:57:46 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"


t_toolbox   ft_toolbox_init(t_toolbox *box, int ac, char **av)
{
    box->nb = ac - 1;
    box->index = ft_index_values(ac, av);
    box->list = NULL;
    return(*box);
}

int main(int ac, char **av)
{
    //t_list_int  *list;
    t_toolbox box;

   
    int i;
    i = 1;
    //je check d'abord les erreurs 
    if (ac <= 1)
        return(0);
    if (ft_check_error(av, ac) == 1)
		return (write(2, "Error\n", 6), 1);
    // j'initialise tous mes outils 
    ft_toolbox_init(&box, ac, av);
    // je range mes valeurs dans une liste chainee 
	while (av[i])
		ft_lstadd_back_int(&box.list, ft_lstnew_int(ft_atol(av[i++])));
	print_list(box.list);
    /*tab = ft_index_values(av, ac);
    i = 0;
    while(tab[i])
    {
        printf("index: %d\n", tab[i]);
        i++;
    }*/
    return(0);
}