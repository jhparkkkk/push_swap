/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:07:02 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/14 16:54:39 by jeepark          ###   ########.fr       */
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

t_toolbox    ft_sort_three(t_toolbox *box)
{
    t_list_int *tmp;
    
    tmp = box->list_a;
    while (tmp->next)
    {
        if (tmp->content > tmp->next->content)
        {
            ft_swap_a(box);
            write(1, "sa\n", 3);
        }
        tmp = tmp->next;
    }
    if (box->list_a->next->content > tmp->content)
    {    
        ft_reverse_rotate_a(box);
        write(1, "ra\n", 3);
    }
    return(*box);
}



int main(int ac, char **av)
{
    
    t_toolbox box;
    //static t_moves const;                            


    if (ac <= 1)                              //je check d'abord les erreurs 
        return(0);   
    if (ft_check_error(av, ac) == 1)
		return (write(2, "Error\n", 6), 1);
    if (ac == 2)
    {
        write(1, av[1], ft_strlen(av[1]));
        return(0);
    }
    ft_toolbox_init(&box, ac, av);            // j'initialise tous mes outils
    printf("%s\n", "here's my list");
    print_list(box.list_a);

    printf("-------SORT THREE--------\n");
    if (ac == 4)
        ft_sort_three(&box);
    print_list(box.list_a);
    /*printf("---------SWAP--------\n");
    ft_swap_a(&box);
    printf("**** LIST A ****\n");
    print_list(box.list_a);
    printf("**** LIST B ****\n");
    print_list(box.list_b);

    
    printf("-------PUSH_A-------\n");
    ft_push_a(&box);
    printf("**** LIST A ****\n");
    print_list(box.list_a);
    printf("**** LIST B ****\n");
    print_list(box.list_b);
    
    printf("--------PUSH_B-------\n");
    ft_push_b(&box);
    printf("**** LIST A ****\n");
    print_list(box.list_a);
    printf("**** LIST B ****\n");
    print_list(box.list_b);
    

    printf("--------ROTATE-------\n");
    ft_rotate_a(&box);
    printf("**** LIST A ****\n");
    print_list(box.list_a);
    printf("**** LIST B ****\n");
    print_list(box.list_b);

    printf("------REVERSE ROTATE-------\n");
    ft_reverse_rotate_a(&box);
    printf("**** LIST A ****\n");
    print_list(box.list_a);
    printf("**** LIST B ****\n");
    print_list(box.list_b);*/
    return(0);
}