/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:42:55 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/10 17:27:19 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

long	ft_atol(const char	*str)
{
	long	nb;
	int		neg;

	nb = 0;
	neg = 1;
	if ((*str >= 9 && *str <= 13) || *str == 32)
	{
		write(2, "Error\n", 6);
		exit (1);
	}	
	if (*str == '-')
		neg *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	nb *= neg;
	if (nb <= INT_MIN || nb >= INT_MAX)
	{
		write(2, "Error\n", 6);
		exit (1);
	}	
	return (nb);
}