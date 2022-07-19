/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:47:00 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/19 01:39:07 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The node is initialised with atoll because if an integer is given beyond the
 * regular integer range, then you would get some kind of garbage value when 
 * smashed into just 4 bytes. 
 */
static t_list	*init_node(char *argv)
{
	size_t	i;
	int64_t	nbr;

	i = 0;
	while (*argv == '0' || argv[0] == '-' || argv[0] == '+')
		argv++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i++]))
			display_error("input contains something"
				"different than digits");
	}
	if (i <= 10)
	{
		nbr = ft_atoll(argv);
		if (nbr <= INT_MAX && nbr >= INT_MIN)
			return (ft_lstnew(&nbr));
	}
	return (display_error("Input is too high or low"), NULL);
}

/**
 * Initialising the given main arguments in a linked list. 
 * Converting from string to integer and checking for duplicates. 
 */
t_list	*init_stack_a(char **argv)
{
	size_t	i;
	t_list	*node;
	t_list	*prev_node;
	t_list	*head;

	i = 1;
	head = init_node(*argv++);
	prev_node = head;
	while (*argv != NULL)
	{
		node = init_node(*argv++);
		prev_node->next = node;
		prev_node = node;
	}
	return (head);
}

int32_t	main(int32_t argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	argc = 0;
	stack_a = init_stack_a(argv);
	stack_b = ft_lstnew(0);
}
