/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:52:42 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/29 02:08:16 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	check_sorting(t_llist *stack_a)
{
	while (stack_a->next != NULL)
	{
		ft_printf_fd(STDOUT_FILENO, "index: %d\n", stack_a->index);
		if (stack_a->next->index - stack_a->index != 1)
		{
			ft_printf_fd(STDOUT_FILENO, "0 ");
			return (false);
		}
		ft_printf_fd(STDOUT_FILENO, "1 ");
		stack_a = stack_a->next;
		ft_printf_fd(STDOUT_FILENO, "2 ");
	}
	ft_printf_fd(STDOUT_FILENO, "3 ");
	return (true);
}


void	back_to_a(t_llist *stack_a, t_llist *stack_b)
{
	while (stack_b != NULL)
	{
		pa(&stack_a, &stack_b);
		stack_b->next = stack_b;
	}
}

void	push_to_b(t_llist *stack_a, t_llist *stack_b, size_t i)
{
	while (stack_a != NULL)
	{
		// ft_printf_fd(STDOUT_FILENO, "bbbb ");
		if (((stack_a->index >> i) & 1) == 0)
			pb(&stack_a, &stack_b);
		else
			ra(&stack_a, true);
		stack_a->next = stack_a;
	}
}

/** 
 * 15 & 1 14
 * 5 1111 1110
 * 1 0001 0001
 * -----
 * 1 0001 0000
 */

void	radix(t_llist *stack_a, t_llist *stack_b)
{
	size_t	i;

	i = 31;
	ft_lstprint_fd(stack_a, 'd', STDOUT_FILENO);
	while (!(check_sorting(stack_a)))
	{
		ft_printf_fd(STDOUT_FILENO, "yo ");
		while (i >= 0)
		{
			ft_printf_fd(STDOUT_FILENO, "aaa ");
			push_to_b(stack_a, stack_b, i--);
			ft_lstprint_fd(stack_a, 'd', STDOUT_FILENO);
			back_to_a(stack_a, stack_b);
			ft_lstprint_fd(stack_a, 'd', STDOUT_FILENO);
		}
		i = 31;
	}
	ft_printf_fd(STDOUT_FILENO, "oi ");
}

/**
 * I will check what the highest index is that I will be sorting, 
 * for example: 
 * 
 */

/**
 * stack a: 010 001 111 
 * stack b: 
 * 
 * stack a: 001 111 
 * stack b: 010
 * 
 * stack a: 010 001 111 
 * stack b: 
 * 
 * stack a: 010 111
 * stack b: 001
 * 
 * stack a: 001 010 111  
 * stack b: 
 * 
 * answer: 
 * stack a: 001 010 111
 */