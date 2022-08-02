/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:47:03 by mialbert          #+#    #+#             */
/*   Updated: 2022/08/01 23:58:49 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * First you need to get the smallest number,
 * remember what the smallest number is, 
 * increase the index and check what the next smallest number is, while
 * being bigger than the previous smallest. 
 */
size_t	indexing(t_llist *head)
{
	size_t	index;
	size_t	lst_size;
	t_llist	*lst;
	t_llist	*smol;

	index = 0;
	lstset(head, -1);
	lst_size = lstsize(head);
	while (index < lst_size)
	{
		lst = head;
		while (lst->next != NULL && lst->index >= 0)
			lst = lst->next;
		smol = lst;
		lst = head;
		while (lst->next != NULL)
		{
			if (lst->next->content < smol->content && lst->next->index < 0)
				smol = lst->next;
			lst = lst->next;
		}
		smol->index = index++;
	}
	return (lst_size);
}
