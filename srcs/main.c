/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:45:49 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/29 16:46:04 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int32_t	main(int32_t argc, char **argv)
{
	t_llist	*stack_a;
	t_llist	*stack_b;

	argc = 0;
	stack_a = ft_calloc(1, sizeof(t_list));
	stack_b = lstnew(8);
	init_stack_a(stack_a, argv);
	indexing(stack_a);
	// ft_lstprint_fd(stack_a, 'd', STDOUT_FILENO);
	// ft_lstprint_fd(stack_b, 'd', STDOUT_FILENO);
	// radix(stack_a, stack_b);
	// pb(&stack_a, &stack_b);
	ra(&stack_a, true);
	// ft_lstprint_fd(stack_a, 'd', STDOUT_FILENO);
	// ft_lstprint_fd(stack_b, 'd', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
