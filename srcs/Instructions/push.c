/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:46:53 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/28 01:34:11 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_llist **stack_a, t_llist **stack_b)
{
	t_llist	*tmp;

	if (!(*stack_a)->content)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(STDOUT_FILENO, "pa\n", 3);
}

void	pb(t_llist **stack_a, t_llist **stack_b)
{
	t_llist	*tmp;

	if (!(*stack_b)->content)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(STDOUT_FILENO, "pb\n", 3);
}
