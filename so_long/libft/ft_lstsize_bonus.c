/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:30:01 by mdaryn            #+#    #+#             */
/*   Updated: 2021/10/21 20:30:03 by mdaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*new_list;
	int		i;

	i = 0;
	new_list = lst;
	while (new_list)
	{
		new_list = new_list->next;
		i++;
	}
	return (i);
}
