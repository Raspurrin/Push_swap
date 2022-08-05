/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:49:32 by mialbert          #+#    #+#             */
/*   Updated: 2022/08/05 02:25:56 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	lstset(t_llist *lst, int32_t nbr)
{
	if (!lst)
		return ;
	while (lst != NULL)
	{
		lst->index = nbr;
		lst = lst->next;
	}
}

void	lstclear(t_llist **lst)
{
	t_llist	*tmp;

	tmp = *lst;
	if (!lst)
		return ;
	while (tmp != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	tmp = NULL;
}

t_llist	*lstnew(int32_t nbr)
{
	t_llist	*node;

	node = malloc(sizeof(t_list));
	node->index = -1;
	node->content = nbr;
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
