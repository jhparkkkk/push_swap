#include "libft.h"
#include "push_swap.h"

static t_toolbox ft_sort_two(t_toolbox *box)
{
    if (box->list_a->content > box->list_a->next->content)
    {
        ft_swap_a(box);
        exit(1);
    }
    exit(1);
}

t_toolbox    ft_sort_three(t_toolbox *box)
{
    t_list_int *tmp;
    int         min;
	int			max;
	t_list_int  *last;
	int i;

    if(box->count == 2)
        ft_sort_two(box);
    i = 0;
	tmp = box->list_a;
	last = ft_lstlast_int(tmp);
    min = ft_find_min(box);
	max = ft_find_max(box);
	while(box->list_a->next->next->content != max)
	{
		ft_reverse_rotate_a(box);
        write(1, "rra\n", 4);
        compteur++;
	}
	if(box->list_a->next->content == min)
	{
		ft_swap_a(box);	
	}
    return(*box);
}


t_toolbox   ft_sort_five(t_toolbox *box)
{
    t_list_int *tmp;
    int i;

    tmp = box->list_a;
    i = 0;
    
    while(tmp->content != 0)
    {
        tmp = tmp->next;
        i++;
    }
    while(i > 0)
    {
        ft_rotate_a(box);
        write(1, "ra\n", 3);
        compteur++;
        i--;
    }
    ft_push_b(box);
    tmp = box->list_a;
    while(tmp->content != 1)
    {
        tmp = tmp->next;
        i++;
    }
    while(i > 0)
    {
        ft_rotate_a(box);
        write(1, "ra\n", 3);
        compteur++;
        i--;
    }
    ft_push_b(box);
    ft_sort_three(box);
    ft_push_a(box);
    ft_push_a(box);
    return(*box);        
}