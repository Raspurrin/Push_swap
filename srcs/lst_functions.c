/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:49:32 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/27 01:37:29 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief sets a certain element of a linked list to a certain number.
 * @param lst 
 * @param nbr 
 * @param elem 
 * @return t_llist* 
 */
void	lstset(t_llist *lst, int32_t nbr, int32_t elem)
{
	if (!lst)
		return ;
	elem = 0;
	while (lst != NULL)
	{
		lst->index = nbr;
		lst = lst->next;
	}
}

// void	lstset(void *lst, int32_t nbr, int32_t size)
// {
// 	if (!lst)
// 		return ;

// 	while (lst != NULL)
// 	{
// 		((uint8_t *)lst)[size] = nbr;
// 		lst = lst->next;
// 	}
// }

t_llist	*lstnew(int32_t nbr)
{
	t_llist	*node;

	node = malloc(sizeof(t_list));
	node->index = nbr;
	node->next = NULL;
	return (node);
}

void	lstadd_back(t_llist **lst, t_llist *new)
{
	t_llist	*last;

	if (!lst)
		return ;
	last = lstlast(*lst);
	last->next = new;
}

t_llist	*lstlast(t_llist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
