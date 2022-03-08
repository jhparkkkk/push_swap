/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:04:51 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/06 23:55:51 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "push_swap.h"
#include "libft.h"

int main(int ac, char **av)
{
    char *s;
    
    if (ac < 2)
        return(0);
    
    s = get_next_line(1);
    printf("%s\n", s);
    free(s);
}