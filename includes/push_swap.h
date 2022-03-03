/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:45:49 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/03 18:35:13 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_toolbox
{
	int			count;
	int			lim_max;
	int			max;
	int			max_pos;
	int			*values;
	int			*lis;
	t_list_int	*list_a;
	t_list_int	*list_b;
}				t_toolbox;

typedef struct s_moves
{
	int			rb;
	int			ra;
	int			rra;
	int			rrb;
	int			ra_opti;
	int			rb_opti;
	int			rra_opti;
	int			rrb_opti;
	int			rr;
	int			rrr;
	int			price;
	int			cost;
	int			execution;
}				t_moves;

int			ft_check_error(char **av, int ac);
t_toolbox	ft_toolbox_init(t_toolbox *box, int ac, char **av);

int			ft_lstlen(t_toolbox *box);
int			ft_check_sorted_list_a(t_toolbox *box);
int			ft_find_min(t_toolbox *box);
int			find_min_pos(t_toolbox *box);
int			ft_find_max(t_toolbox *box);

void		ft_swap_a(t_toolbox *box);
void		ft_swap_b(t_toolbox *box);
void		ft_swap_ss(t_toolbox *box);
void		ft_push_a(t_toolbox *box);
void		ft_push_b(t_toolbox *box);
void		ft_rotate_a(t_toolbox *box);
void		ft_rotate_b(t_toolbox *box);
void		ft_rotate_rr(t_toolbox *box);
void		ft_reverse_rotate_a(t_toolbox *box);
void		ft_reverse_rotate_b(t_toolbox *box);
void		ft_reverse_rotate_rr(t_toolbox *box);

t_toolbox	ft_sort_three(t_toolbox *box);
t_toolbox	ft_sort_five(t_toolbox *box);

int			*ft_tab_lis(t_toolbox *box);

t_toolbox	boarding_gate(t_toolbox *box);
void		meta_simulation(t_toolbox *box);
int			find_target(t_toolbox *box, t_moves *menu, int i, int scanning);

void		check_sync_rr(t_moves *menu);
void		check_sync_rrr(t_moves *menu);
void		ft_ra_rb(t_toolbox *box, t_moves *best);
void		ft_rra_rrb(t_toolbox *box, t_moves *best);
void		ft_ra_rrb(t_toolbox *box, t_moves *best);
void		ft_rra_rb(t_toolbox *box, t_moves *best);

void		fasten_your_seatbelt(t_toolbox *box);

void		ft_list_free(t_toolbox *box);

void		print_list(t_list_int *list);

#endif