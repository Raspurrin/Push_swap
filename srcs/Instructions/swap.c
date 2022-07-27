/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:33:50 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/28 01:26:52 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_llist **stack_a, bool print)
{
	t_llist	*node;

	if (lstsize(*stack_a) <= 1)
		return ;
	node = *stack_a;
	*stack_a = (*stack_a)->next;
	node->next = (*stack_a)->next;
	(*stack_a)->next = node;
	if (print)
		write(STDOUT_FILENO, "sa\n", 3);
}

void	sb(t_llist **stack_b, bool print)
{
	t_llist	*node;

	if (lstsize(*stack_b) <= 1)
		return ;
	node = *stack_b;
	*stack_b = (*stack_b)->next;
	node->next = (*stack_b)->next;
	(*stack_b)->next = node;
	if (print)
		write(STDOUT_FILENO, "sb\n", 3);
}

void	ss(t_llist **stack_a, t_llist **stack_b)
{
	sa(stack_a, false);
	sb(stack_b, false);
	write(STDOUT_FILENO, "ss\n", 3);
}
