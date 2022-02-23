/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mission.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:40:52 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/24 00:28:54 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void check_sync(t_moves *menu)
{
     if (menu->ra_opti > 0 && menu->rb_opti > 0)
    {
        while (menu->ra_opti || menu->rb_opti )
        {
            menu->ra_opti--;
            menu->rb_opti--;
            menu->rr++;
            if (menu->ra_opti == 0 || menu->rb_opti == 0)
                break ;
        }
    }
    
    if (menu->rra_opti > 0 && menu->rrb_opti > 0)
    {
        while (menu->rra_opti || menu->rrb_opti)
        {
            menu->rra_opti--;
            menu->rrb_opti--;
            menu->rrr++;
            if (menu->rra_opti == 0 || menu->rrb_opti == 0)
                break ;
        }
    }
}

//t_moves reset_setting(t_toolbox *box, t_moves *menu)

t_moves init_settings(t_toolbox *box, t_moves *menu)
{
    menu->ra = find_target(box);
    menu->rb = 0;
    menu->rra = box->max - menu->ra;
    menu->rrb = box->count - menu->rb;
    menu->ra_opti = menu->ra;
    menu->rb_opti = 0;
    menu->rra_opti = menu->rra;
    menu->rrb_opti = menu->rrb;
    menu->rr = 0;
    menu->rrr = 0;
    menu->price = ft_calloc(4, sizeof(int));
    menu->execution = 0;
    return(*menu);
}

void ft_ra_rb(t_toolbox *box, t_moves *menu)
{
        if(menu->rr)
        {  
            ft_rotate_rr(box);
            menu->rr--;
            ft_ra_rb(box, menu);
        }
        if(menu->ra_opti)
        {
            ft_rotate_a(box);
            menu->ra_opti--;
            ft_ra_rb(box, menu);
        }
        if(menu->rb_opti)
        {
            ft_rotate_b(box);
            menu->rb_opti--;
            ft_ra_rb(box, menu);
        } 
}
void ft_rra_rrb(t_toolbox *box, t_moves *menu)
{
        if(menu->rrr)
        {  
            ft_reverse_rotate_rr(box);
            menu->rrr--;
            ft_rra_rrb(box, menu);
        }
        if(menu->rra_opti)
        {
            ft_reverse_rotate_a(box);
            menu->rra_opti--;
            ft_rra_rrb(box, menu);
        }
        if(menu->rrb_opti)
        {
            ft_reverse_rotate_b(box);
            menu->rrb_opti--;
            ft_rra_rrb(box, menu);
        } 
}

void ft_ra_rrb(t_toolbox *box, t_moves *menu)
{
        if(menu->ra)
        {
            ft_rotate_a(box);
            menu->ra--;
            ft_ra_rrb(box, menu);
        }
        if(menu->rrb)
        {
            ft_reverse_rotate_b(box);
            menu->rrb--;
            ft_ra_rrb(box, menu);
        } 
}

void ft_rra_rb(t_toolbox *box, t_moves *menu)
{
        if(menu->rra)
        {
            ft_reverse_rotate_a(box);
            menu->rra--;
            ft_rra_rb(box, menu);
        }
        if(menu->rb)
        {
            ft_rotate_b(box);
            menu->rrb--;
            ft_rra_rb(box, menu);
        } 
}


void    execution(t_toolbox *box, t_moves *menu)
{
	if (menu->execution == 0)
	{
		ft_ra_rb(box, menu);
		ft_push_a(box);
		box->count--;
		box->max++;
	}
	if (menu->execution == 1)
	{
		ft_rra_rrb(box, menu);
		ft_push_a(box);
		box->count--;
		box->max++;
	}
	if (menu->execution == 2)
	{
		ft_ra_rrb(box, menu);
		ft_push_a(box);
		box->count--;
		box->max++;
	}
	if (menu->execution == 3)
	{
		ft_rra_rb(box, menu);
		ft_push_a(box);
		box->count--;
		box->max++;
	}
	
}

void simulation(t_toolbox *box, t_moves *menu)
{
    int min;
    int i;
    
    i = 0;
    init_settings(box, menu);
    check_sync(menu);
    
    menu->price[0] = menu->ra_opti + menu->rb_opti + menu->rr;
    menu->price[1] = menu->rra_opti + menu->rrb_opti + menu->rrr;
    menu->price[2] = menu->ra + menu->rrb;
    menu->price[3] = menu->rra + menu->rb;
    min = menu->price[0];
    while(i < 4)
    {
        if (menu->price[i] <= min)
        {
            min = menu->price[i];
            menu->execution = i;
        }
        i++;
    }
}

void meta_simulation(t_toolbox *box, t_moves *menu)
{
	int try;
	try = box->count

	while (try >= 0)
{
	simulation(box, menu);
	menu->rb++;
	try--;
}


