/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:48:30 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/13 12:48:32 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int  *ft_index_tab_init(int ac, char **av)
{
	int i;
	int j;
	int *index_tab;
	
	i = 1;
	j = 0;
	index_tab = ft_calloc((ac), 4);
	while(av[i])
	{
		index_tab[j] = ft_atol(av[i]);
		i++;
		j++;
	}
    return(index_tab);
}

static int  *ft_sort_int_tab(int *tab, int ac)
{
    int i;
    int j;
    int tmp;
    i = 0;
	
    while (i < (ac - 1))
    {
        j = i + 1;
        while (j < (ac - 1))
        {
            if (tab[i] > tab[j])
            {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
            j++;
        }
        i++;
    }
	return (tab);                     
}

int *ft_index_values(int ac, char **av)
{
    int *index_tab;
	int i;

	i = 0;
    index_tab = ft_index_tab_init(ac, av);
	index_tab = ft_sort_int_tab(index_tab, ac);
	// reste a trouver comment indexer mes valeurs dans l'ordre original 
	while(index_tab[i])
	{
		index_tab[i] = i;
		printf("%d\n", index_tab[i]);
		i++;
	}
	return(index_tab);
}