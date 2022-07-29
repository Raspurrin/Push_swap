/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:33:55 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/28 01:33:06 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_llist **stack_a, bool print)
{
	t_llist	*tmp;
	t_llist	*lst;

	tmp = *stack_a;
	lst = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstprint_fd(*stack_a, 'd', STDOUT_FILENO);
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = tmp;
	tmp->next = NULL;
	if (print)
		write(STDOUT_FILENO, "ra\n", 3);
}

void	rb(t_llist **stack_b, bool print)
{
	t_llist	*tmp;
	t_llist	*lst;

	tmp = *stack_b;
	lst = *stack_b;
	stack_b = &(*stack_b)->next;
	while (lst != NULL)
		lst = lst->next;
	lst->next = tmp;
	if (print)
		write(STDOUT_FILENO, "rb\n", 3);
}

void	rr(t_llist **stack_a, t_llist **stack_b)
{
	ra(stack_a, false);
	rb(stack_b, false);
	write(STDOUT_FILENO, "rr\n", 3);
}
