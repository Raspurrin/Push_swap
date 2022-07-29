/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:33:53 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/28 01:33:12 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * stack_a -> 4 -> 3 -> 2 -> NULL
 * 			start* mid* end*
 * stack_a -> 2(end) -> NULL | 4 -> 3 -> 2 -> NULL
 * 3(mid) -> NULL
 * stack_a -> 2 -> 4(start) -> 3 -> NULL
 */
void	rra(t_llist **stack_a, bool print)
{
	t_llist	*start;
	t_llist	*mid;
	t_llist	*end;

	start = *stack_a;
	mid = *stack_a;
	end = *stack_a;
	while (end->next != NULL)
	{
		if (end->next->next == NULL)
			mid = end;
		end = end->next;
	}
	*stack_a = end;
	mid->next = NULL;
	end->next = start;
	if (print == true)
		write(STDOUT_FILENO, "rra\n", 4);
}

void	rrb(t_llist **stack_b, bool print)
{
	t_llist	*start;
	t_llist	*mid;
	t_llist	*end;

	start = *stack_b;
	mid = *stack_b;
	end = *stack_b;
	while (end->next != NULL)
	{
		if (end->next->next == NULL)
			mid = end;
		end = end->next;
	}
	*stack_b = end;
	mid->next = NULL;
	end->next = start;
	if (print == true)
		write(STDOUT_FILENO, "rrb\n", 4);
}

void	rrr(t_llist **stack_a, t_llist **stack_b)
{
	rra(stack_a, false);
	rrb(stack_b, false);
	write(STDOUT_FILENO, "rrr\n", 4);
}
