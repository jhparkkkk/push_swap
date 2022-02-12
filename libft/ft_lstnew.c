/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:35:40 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/09 18:47:40 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*house;

	house = (t_list *)malloc(sizeof(*house));
	if (!house)
		return (NULL);
	house->content = content;
	house->next = NULL;
	return (house);
}