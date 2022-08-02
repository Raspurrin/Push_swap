/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:46:53 by mialbert          #+#    #+#             */
/*   Updated: 2022/08/03 01:32:37 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Pushes the top node from stack b to stack a.
 * stack_a -> 4 -> 3 -> 2 -> NULL
 * stack_b -> 8
 * tmp* ^
 * 
 */
void	pa(t_llist **stack_a, t_llist **stack_b)
{
	t_llist	*tmp;

	if (!*stack_b)
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

	if (!*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(STDOUT_FILENO, "pb\n", 3);
}
