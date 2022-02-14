/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:48:30 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/14 23:07:45 by jeepark          ###   ########.fr       */
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
	int *copy;
	
    i = 0;
	copy = tab;
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
	printf("TAB POS 1 ==== %d\n", tab[0]);
	printf("TAB POS 2 ==== %d\n", tab[1]);
	printf("TAB POS 3 ==== %d\n", tab[2]);
	printf("TAB POS 4 ==== %d\n", tab[3]);
	
	printf("COPY 1 ==== %d\n", copy[0]);
	printf("COPY 2 ==== %d\n", copy[1]);
	printf("COPY 3 ==== %d\n", copy[2]);
	printf("COPY 4 ==== %d\n", copy[3]);
	return (copy);                     
}


int *ft_index_values(int ac, char **av)
{
    int *tab;
	int *sorted_tab;
	int i;
	int j;

	i = 0;
	j = 0;
    tab = ft_index_tab_init(ac, av);
	printf("TAB POS 1 ==== %d\n", tab[0]);
	printf("TAB POS 2 ==== %d\n", tab[1]);
	printf("TAB POS 3 ==== %d\n", tab[2]);
	printf("TAB POS 4 ==== %d\n", tab[3]);
	sorted_tab = ft_sort_int_tab(tab, ac);
	printf("SORTED TAB POS 1 ==== %d\n", sorted_tab[0]);
	printf("SORTED TAB POS 2 ==== %d\n", sorted_tab[1]);
	printf("SORTED TAB POS 3 ==== %d\n", sorted_tab[2]);
	printf("SORTED TAB POS 4 ==== %d\n", sorted_tab[3]);

	printf("TAB POS 1 ==== %d\n", tab[0]);
	printf("TAB POS 2 ==== %d\n", tab[1]);
	printf("TAB POS 3 ==== %d\n", tab[2]);
	printf("TAB POS 4 ==== %d\n", tab[3]);
	// reste a trouver comment indexer mes valeurs dans l'ordre original 
	printf("TAB[J] ==== %d\n", tab[j]);
	while(tab[j])
	{
		tab[j] = 0;
		if (sorted_tab[i] == tab[j])
		{
			tab[j] = i;
			i++;
		}
		j++;
	}
	return(tab);
}