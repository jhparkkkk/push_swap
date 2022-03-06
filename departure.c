/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   departure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:42:53 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/06 20:14:20 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstlen_b(t_toolbox *box)
{
	t_list_int	*tmp;
	int			i;

	i = 0;
	tmp = box->list_b;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	i++;
	return (i);
}

static int  *ft_tab_sort(t_toolbox *box)
{
    int i;
    int j;
    int tmp;
	int *copy;
    i = 0;
	copy = ft_calloc(box->count, sizeof(int));
	while (i < box->count)
	{
		copy[i] = box->values[i];
		i++;
	}
	i = 0;
	j = 0;
    while (i < box->count)
    {
        j = i + 1;
        while (j < box->count)
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
	/*i = 0;
	while(copy[i])
	{
		printf("copy[%d] = %d\n", i, copy[i]);
		i++;
	}*/
	return(copy);                     
}

static int	find_mediane(t_toolbox *box)
{
	int mediane =  box->count / 2;
	int *sorted_tab;
	sorted_tab = ft_tab_sort(box);
	//printf("MEDIANE = %d\n", sorted_tab[mediane]);
	return(sorted_tab[mediane]);
}

int	control_visa(t_toolbox *box, t_list_int *tmp)
{
	int	valid_visa;

	valid_visa = 0;
	while (valid_visa < box->max)
	{
		if (tmp->content == box->lis[valid_visa])
			return (0);
		valid_visa++;
	}
	return (1);
}

t_toolbox	boarding_gate(t_toolbox *box)
{
	//int	passenger;
	int	scanning;
	t_list_int *tmp;
	int	mediane;
	int compteur;
	//passenger = 0;
	scanning = box->count;
	tmp = box->list_a;
	mediane = find_mediane(box);

	compteur = box->count - box->max;
	//printf("MEDIANE = %d\n", mediane);
	while (scanning > 0 || compteur > 0)
	{
		//printf("PASSENGER %d = %d\n", scanning, tmp->content);
		if (control_visa(box, tmp) == 0)
		{
			
			ft_rotate_a(box);
			write(1, "ra\n", 3);
		}
		else
		{
			if (tmp->content < mediane)
			{
				//printf("coucou\n");
				ft_push_b(box);
				if (ft_lstlen_b(box) > 1)
				{
					ft_rotate_b(box);
					write (1, "rb\n", 3);
				}
			}
			else
				ft_push_b(box);
			compteur--;
		}
		tmp = box->list_a;
		scanning--;
	}
	box->count -= box->max;
	return (*box);
}
