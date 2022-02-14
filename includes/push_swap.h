/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:45:49 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/14 16:51:23 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H
#include "libft.h"
typedef struct s_toolbox
{
    int         nb;
    int         *index;
    t_list_int  *list_a;
    t_list_int  *list_b; 
}               t_toolbox;

/*typedef struct s_moves              // A voir avec
{
    char    *key;
    void    (*value)(t_toolbox *);
}           t_moves; 

void    ft_swap_a(t_toolbox *box);
void    ft_swap_b(t_toolbox *box);
void    ft_swap_ss(t_toolbox *box);

static t_moves const moves[] = 
{
    {"sa", ft_swap_a},
    {"sb", ft_swap_b},
    {"ss", ft_swap_ss},
    {0}
};*/

int     ft_check_error(char **av, int ac);
void    print_list(t_list_int *list);
int     *ft_index_values(int ac, char **av);
int     ft_lstlen(t_toolbox *box);
void    ft_swap(t_toolbox *box);
void    ft_push(t_toolbox *box);
void    ft_rotate(t_toolbox *box);
void    ft_reverse_rotate(t_toolbox *box);

/*************SWAP***************/
void    ft_swap_a(t_toolbox *box);
void    ft_swap_b(t_toolbox *box);
void    ft_swap_ss(t_toolbox *box);

/*************PUSH***************/
void    ft_push_a(t_toolbox *box);
void    ft_push_b(t_toolbox *box);

/*************ROTATE**************/
void    ft_rotate_a(t_toolbox *box);
void    ft_rotate_b(t_toolbox *box);
void    ft_rotate_rr(t_toolbox *box);

/*********REVERSE ROTATE***********/
void    ft_reverse_rotate_a(t_toolbox *box);
void    ft_reverse_rotate_b(t_toolbox *box);
void    ft_reverse_rotate_rr(t_toolbox *box);

#endif