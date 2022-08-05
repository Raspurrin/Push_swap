/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:45:49 by mialbert          #+#    #+#             */
/*   Updated: 2022/08/05 02:24:24 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int32_t	main(int32_t argc, char **argv)
{
	t_llist	*stack_a;
	t_llist	*stack_b;
	size_t	lst_size;

	argc = 0;
	stack_a = ft_calloc(1, sizeof(t_llist));
	stack_b = NULL;
	init_stack_a(&stack_a, argv);
	lst_size = lstsize(stack_a);
	indexing(stack_a, lst_size);
	if (check_sorting(stack_a))
		exit(0);
	if (lst_size == 3)
		case_3(&stack_a);
	else if (lst_size == 5)
		case_5(&stack_a, &stack_b, lst_size);
	else
		radix(&stack_a, &stack_b, lst_size);
	lstclear(&stack_a);
	return (EXIT_SUCCESS);
}
Co