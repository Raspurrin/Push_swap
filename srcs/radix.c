/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:52:42 by mialbert          #+#    #+#             */
/*   Updated: 2022/08/05 02:25:27 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	check_sorting(t_llist *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->next->content < stack_a->content)
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
		while (i < lst_size)
		{
			if ((((*stack_a)->index >> j) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a, true);
			i++;
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b);
		i = 0;
		j++;
	}
}
