/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:49:32 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/25 23:58:43 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



int	lstsize(t_llist *lst)
{
	t_llist	*counter;
	size_t	i;

	counter = lst;
	i = 0;
	if (!lst)
		return (0);
	while (counter != NULL)
	{
		counter = counter->next;
		i++;
	}
	return (i);
}

t_llist	*lstnew(int32_t nbr)
{
	t_llist	*node;

	node = malloc(sizeof(t_list));
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
