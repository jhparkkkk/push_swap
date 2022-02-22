/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:45:49 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/22 11:50:53 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H
#include "libft.h"
typedef struct s_toolbox
{
    int         count;
    int         max;
    int         max_pos;
    int         *values;
    int         *index;
    int         *lis;
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

/************PARSING*************/
int         ft_check_error(char **av, int ac);
int         *ft_index_tab_init(int ac, char **av);
int         *ft_index_values(int ac, char **av);
t_list_int  *ft_list_init_tab(t_toolbox *box);
t_toolbox   ft_toolbox_init(t_toolbox *box, int ac, char **av);

/*************UTILS**************/
void    print_list(t_list_int *list);
int     ft_lstlen(t_toolbox *box);
int     ft_check_sorted_list_a(t_toolbox *box);
int     ft_check_sorted_list_b(t_toolbox *box);
int		ft_find_min(t_toolbox *box);
int		ft_find_max(t_toolbox *box);

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

/*********SORTING LITTLE LISTS***********/
t_toolbox    ft_sort_three(t_toolbox *box);
t_toolbox   ft_sort_five(t_toolbox *box);

/***************SORTING*****************/
int *find_lis_len(t_toolbox *box);
int	*ft_find_lis_pos(t_toolbox *box);
int *ft_lis_keeper(t_toolbox *box);

/**************FLY TO B*****************/
t_toolbox boarding_gate(t_toolbox *box);
int control_visa(t_toolbox *box);

/************SIMULATION*****************/
int find_target(t_toolbox *box);
#endif