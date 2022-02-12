/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:06:11 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/12 16:43:10 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int ft_is_numeric(char *av)
{
    int i;
	int j;
    i = 0;
    while (av[i])
    {
        if (ft_isdigit(av[i]) == 0 && av[i] != ' ' && av[i] != '-')
            return (1);
        if (av[i] == '-')
		{
			j = i + 1;
			while(av[j])
			{
				if (ft_isdigit(av[j]) == 0) 
            		return(1);
				j++;
			}
		}
        i++;
    }
    return (0);
}


static int ft_is_right_nb(char **av, int ac)
{
	int i;
	int j;
	int *box;
	
	i = 1;
	j = 0;
	box = ft_calloc((ac - 1), 4);
	while(av[i])
	{
		box[j] = ft_atol(av[i]);
		i++;
		j++;
	}
	j = 0;
	i = 1;
	while(box[j] && i <= ac)
	{	
		if (box[j] == box[i])
		{
			free(box);
			return(1);
		}
		i++;
	}
	free(box);
	return(0);
}

int   ft_check_error(char **av, int ac)
{   
	int	i;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '\0')
			return(1);
		if (ft_is_numeric(av[i]) == 1 || ft_is_right_nb(&av[i], ac) == 1)
			return (1);
		i++;
	}
	return (0);
}
