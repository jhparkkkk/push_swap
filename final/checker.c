/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:04:51 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/08 14:54:53 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	moves_r(char *move, t_toolbox *checker)
{
	if (ft_strcmp(move, "ra\n") == 0)
	{
		ft_rotate_a(checker);
		write(1, "ra\n", 3);
	}
	else if (ft_strcmp(move, "rb\n") == 0)
	{
		ft_rotate_b(checker);
		write(1, "rb\n", 3);
	}
	else if (ft_strcmp(move, "rr\n") == 0)
	{
		ft_rotate_rr(checker);
		write(1, "rr\n", 3);
	}
}

void	moves_rr(char *move, t_toolbox *checker)
{
	if (ft_strcmp(move, "rra\n") == 0)
	{
		ft_reverse_rotate_a(checker);
		write(1, "rra\n", 4);
	}
	else if (ft_strcmp(move, "rrb\n") == 0)
	{
		ft_reverse_rotate_b(checker);
		write(1, "rrb\n", 4);
	}
	else if (ft_strcmp(move, "rrr\n") == 0)
	{
		ft_reverse_rotate_rr(checker);
		write(1, "rrr\n", 4);
	}	
}

void	go(char *move, t_toolbox *checker)
{
	if (ft_strcmp(move, "pa\n") == 0)
		ft_push_a(checker);
	else if (ft_strcmp(move, "pb\n") == 0)
		ft_push_b(checker);
	else if (ft_strcmp(move, "sa\n") == 0)
		ft_swap_a(checker);
	else if (ft_strlen(move) == 3)
		moves_r(move, checker);
	else if (ft_strlen(move) == 4)
		moves_rr(move, checker);
}

void	display_checker(t_toolbox *checker)
{
	if (ft_check_sorted_list_a(checker) == 0 && (!checker->list_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_toolbox	checker;
	char		*move;
	int			i;

	i = 0;
	move = NULL;
	if (ac < 2)
		return (0);
	ft_check_error(av, ac);
	ft_toolbox_init(&checker, ac, av);
	while (move != NULL || i == 0)
	{
		if (move)
			free(move);
		move = get_next_line(0);
		if (!move)
			break ;
		go(move, &checker);
		i = 1;
	}
	display_checker(&checker);
	if (ac <= 4 || ac == 6)
		return (free(checker.values), ft_list_free(&checker), 0);
	return (free(checker.values), ft_list_free(&checker), free(checker.lis), 0);
}
