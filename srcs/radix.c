/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:52:42 by mialbert          #+#    #+#             */
/*   Updated: 2022/08/02 03:26:49 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	check_sorting(t_llist *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->next->index - stack_a->index != 1)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

void	radix(t_llist **stack_a, t_llist **stack_b, size_t lst_size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (!(check_sorting(*stack_a)))
	{
		while (j < lst_size)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a, true);
			j++;
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b);
		j = 0;
		i++;
	}
}
