/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:07:02 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/13 17:10:31 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_list_int  *ft_list_init(t_toolbox *box, char **av)
{
    int i;
    i = 1;
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
    
    t_toolbox box;                            
    
    if (ac <= 1)                              //je check d'abord les erreurs 
        return(0);
    if (ft_check_error(av, ac) == 1)
		return (write(2, "Error\n", 6), 1);
    ft_toolbox_init(&box, ac, av);            // j'initialise tous mes outils
    printf("%s\n", "here's my list");
    print_list(box.list_a);
    ft_swap(&box);
    print_list(box.list_a);
    printf("LIST A BEFORE PUSH\n");
    print_list(box.list_a);
    //printf("LIST B\n");
    //print_list(box.list_b);
    ft_push(&box);
    printf("LIST A AFTER PUSH\n");
    print_list(box.list_a);
    // Pourquoi list_a == tempo ? 
    printf("LIST B\n");
    print_list(box.list_b);
    
    printf("ROTATE PLEASE\n");
    ft_rotate(&box);
    printf("LIST A\n");
    print_list(box.list_a);
    printf("LIST B\n");
    print_list(box.list_b);

    printf("********REVERSE ROTATE PLEASE********\n");
    ft_reverse_rotate(&box);
    printf("LIST A\n");
    print_list(box.list_a);
    printf("LIST B\n");
    print_list(box.list_b);
    return(0);
}