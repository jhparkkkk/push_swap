/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:45:49 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/12 11:53:14 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H

typedef struct s_toolbox
{
    int         nb;
    int         *index;
    t_list_int  *list_a;
    t_list_int  *list_b;
}               t_toolbox;

int   ft_check_error(char **av, int ac);
void print_list(t_list_int *list);
int *ft_index_values(int ac, char **av);
#endif