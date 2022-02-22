/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:48:30 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/21 14:23:08 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"


int  *ft_index_tab_init(int ac, char **av)            //j'initialise mon tableau avec les valeurs av
{
	int i;
	int j;
	int *index_tab;
	
	i = 1;
	j = 0;
	index_tab = ft_calloc(ac -1, sizeof(int));
	while(av[i])
	{
		index_tab[j] = ft_atol(av[i]);
		i++;
		j++;
	}
	i = 0;
    return(index_tab);
}


static int  *ft_sort_int_tab(int *tab, int ac)
{
    int i;
    int j;
    int tmp;
	int *copy;
	int *bin;
    i = 0;
	copy=NULL;
	bin = NULL;
	copy = malloc(sizeof(int) * (ac-1));
	while (i < (ac-1))
	{
		copy[i] = tab[i];
		i++;
	}
	copy[i] = '\0';
	
	i = 0;
	j = 0;
	
    while (i < (ac - 1))
    {
        j = i + 1;
        while (j < (ac - 1))
        {
            if (copy[i] > copy[j])
            {
                tmp = copy[i];
                copy[i] = copy[j];
                copy[j] = tmp;
            }
            j++;
        }
        i++;
	}
	return (copy);                     
}


int *ft_index_values(int ac, char **av)           //j'attribue chaque valeur à son index
{
    int *tab;
	int *sorted_tab;
	int i;
	int j;
	
	i = 0;
	j = 0;
    tab = ft_index_tab_init(ac, av);
	sorted_tab = ft_sort_int_tab(tab, ac);
	while(i < (ac - 1))
	{
		j = 0;
		while(j<(ac -1))
		{
			if (tab[i] == sorted_tab[j])
			{
				tab[i] = j;
				j = ac;
			}
			j++;
		}
		i++;
	}
	return(tab);
}