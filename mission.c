/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mission.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:40:52 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/25 18:43:53 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void   check_sync_rr(t_moves *menu)
{
    int rr;

    rr = 0;
    if (menu->ra_opti > 0 && menu->rb_opti > 0)
    while (menu->ra_opti != 0 || menu->rb_opti !=0 )
    {
            menu->ra_opti--;
            menu->rb_opti--;
            menu->rr++;
            if (menu->ra_opti == 0 || menu->rb_opti == 0)
            {
                break;
            }
    }
}
    
void check_sync_rrr(t_moves *menu)   
{
    int rrr;

    rrr = 0;
    if (menu->rra_opti > 0 && menu->rrb_opti > 0)
    {
        while (menu->rra_opti || menu->rrb_opti)
        {
            menu->rra_opti--;
            menu->rrb_opti--;
            menu->rrr++;
            if (menu->rra_opti == 0 || menu->rrb_opti == 0)
                break;
        }
    }
}


t_moves init_settings(t_toolbox *box, t_moves *menu, int i)
{
   	menu->rb = i;  
	menu->ra = find_target(box, menu);
    menu->rra = box->max - menu->ra;
    menu->rrb = box->count - menu->rb;
    menu->ra_opti = menu->ra;
    menu->rb_opti = menu->rb;
    menu->rra_opti = menu->rra;
    menu->rrb_opti = menu->rrb;
    menu->rr = 0;
    menu->rrr = 0;
    menu->price = 0;
	menu->cost = 0;
    menu->execution = 0;
    return(*menu);
}



t_moves reset_settings(t_moves *menu)
{
   	menu->rb = 0;  
	menu->ra = 0;
    menu->rra = 0;
    menu->rrb = 0;
    menu->ra_opti = 0;
    menu->rb_opti = 0;
    menu->rra_opti = 0;
    menu->rrb_opti = 0;
    menu->rr = 0;
    menu->rrr = 0;
    menu->price = 0;
	menu->cost = 0;
    menu->execution = 0;
    return(*menu);
}

void ft_ra_rb(t_toolbox *box, t_moves *best)
{
        if(best->rr)
        {  
            ft_rotate_rr(box);
			write(1, "rr\n", 3);
            compteur++;
            best->rr--;
            ft_ra_rb(box, best);
        }
        if(best->ra_opti)
        {
            ft_rotate_a(box);
			write(1, "ra\n", 3);
            compteur++;
            best->ra_opti--;
            ft_ra_rb(box, best);
        }
        if(best->rb_opti)
        {
            ft_rotate_b(box);
			write(1, "rb\n", 3);
            compteur++;
            best->rb_opti--;
            ft_ra_rb(box, best);
        } 
}
void ft_rra_rrb(t_toolbox *box, t_moves *best)
{
        if(best->rrr)
        {  
            ft_reverse_rotate_rr(box);
			write(1, "rrr\n", 4);
            compteur++;
            best->rrr--;
            ft_rra_rrb(box, best);
        }
        if(best->rra_opti)
        {
            ft_reverse_rotate_a(box);
			write(1, "rra\n", 4);
            compteur++;
            best->rra_opti--;
            ft_rra_rrb(box, best);
        }
        if(best->rrb_opti)
        {
            ft_reverse_rotate_b(box);
			write(1, "rrb\n", 4);
            compteur++;
            best->rrb_opti--;
            ft_rra_rrb(box, best);
        } 
}

void ft_ra_rrb(t_toolbox *box, t_moves *best)
{
        if(best->ra)
        {
            ft_rotate_a(box);
			write(1, "ra\n", 3);
            compteur++;
            best->ra--;
            ft_ra_rrb(box, best);
        }
        if(best->rrb)
        {
            ft_reverse_rotate_b(box);
			write(1, "rrb\n", 4);
            compteur++;
            best->rrb--;
            ft_ra_rrb(box, best);
        } 
}

void ft_rra_rb(t_toolbox *box, t_moves *best)
{
        if(best->rra)
        {
            ft_reverse_rotate_a(box);
			write(1, "rra\n", 4);
            compteur++;
            best->rra--;
            ft_rra_rb(box, best);
        }
        if(best->rb)
        {
            ft_rotate_b(box);
			write(1, "rb\n", 3);
            compteur++;
            best->rb--;
            ft_rra_rb(box, best);
        } 
}


void    execution(t_toolbox *box, t_moves *best)
{
	if (best->execution == 0)
	{
		ft_ra_rb(box, best);
		ft_push_a(box);
		box->count--;
		box->max++;
	}
	if (best->execution == 1)
	{
		ft_rra_rrb(box, best);
		ft_push_a(box);
		box->count--;
		box->max++;
	}
	if (best->execution == 2)
	{
		ft_ra_rrb(box, best);
		ft_push_a(box);
		box->count--;
		box->max++;
	}
	if (best->execution == 3)
	{
		ft_rra_rb(box, best);
		ft_push_a(box);
		box->count--;
		box->max++;
	}
	
}


void simulation(t_moves *menu)
{
    int *price;
    int i;
	int cost;
	i = 0;
	cost = 0;
    price = ft_calloc(4, sizeof(int));
    price[0] = menu->ra_opti + menu->rb_opti + menu->rr;
    price[1] = menu->rra_opti + menu->rrb_opti + menu->rrr;
    price[2] = menu->ra + menu->rrb;
    price[3] = menu->rra + menu->rb;
    cost = price[0];
    
    while(i < 4)
    {
        if (price[i] <= cost)
        {
            menu->cost = price[i];
            menu->execution = i;
        }
        i++;
    }
    //printf("COST %d\n", menu->cost);
	free(price);
}

void meta_simulation(t_toolbox *box)
{
	int i = 0;
	t_moves menu;
	t_moves best;
    
    menu = init_settings(box, &menu, i);
    check_sync_rr(&menu);
    check_sync_rrr(&menu);
    simulation(&menu);
    memcpy(&best, &menu, sizeof(t_moves));
    i++;
	while (i < box->count)
	{
		menu = init_settings(box, &menu, i);
        check_sync_rr(&menu);
        check_sync_rrr(&menu);
        simulation(&menu);
        if (menu.cost <= best.cost)
		{
            best = menu;
		}
        i++;
	}
    /*printf("\nBEST COST %d\n", best.cost);
    printf("\nBEST EXECUTION %d\n", best.execution);
    printf("\nWITH ASSETS RA%d RB%d RR%d\n", best.ra_opti, best.rb_opti, best.rr);*/
    execution(box, &best);
    
}

