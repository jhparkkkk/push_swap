/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:06:11 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/06 22:15:26 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <limits.h>

static int	ft_is_numeric(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((ft_isdigit(av[i][j]) == 0 && av[i][j] != ' '
			&& av[i][j] != '-')
			|| (av[i][j] == ' ' && av[i][j + 1] == ' '))
				return (1);
			if (av[i][j] == '-')
			{
				if (ft_isdigit(av[i][j + 1]) == 0)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_is_duplicate(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_overflow(char **av, int ac)
{
	int	i;
	int	len;

	i = 1;
	len = 0;
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		if (len >= 10)
		{
			if (ft_atol(av[i]) < INT_MIN || ft_atol(av[i]) > INT_MAX)
				return (1);
		}
		if (len == 0 || len >= 19)
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_error(char **av, int ac)
{
	if ((av[1] && av[1][0] == '\0')
	|| ft_overflow(av, ac) == 1
	|| ft_is_numeric(av) == 1
	|| ft_is_duplicate(av, ac) == 1)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit (1);
	}
}
