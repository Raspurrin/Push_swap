/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:45:49 by mialbert          #+#    #+#             */
/*   Updated: 2022/08/02 03:28:51 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int32_t	main(int32_t argc, char **argv)
{
	t_llist	*stack_a;
	t_llist	*stack_b;

	argc = 0;
	stack_a = ft_calloc(1, sizeof(t_list));
	stack_b = NULL;
	init_stack_a(stack_a, argv);
	// ft_lstprint_fd(stack_a, 'd', STDOUT_FILENO);
	radix(&stack_a, &stack_b, indexing(stack_a));
	// ft_lstprint_fd(stack_a, 'd', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
