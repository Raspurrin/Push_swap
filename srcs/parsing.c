/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:47:00 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/17 21:06:02 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The node is initialised with atoll because if an integer is given beyond the
 * regular integer range, then you would get some kind of garbage value when 
 * smashed into just 4 bytes. 
 */
static t_list	init_node(char **argv, size_t i)
{
	int64_t	nbr;

	
	nbr = ft_atoll(argv[i]);
	if (nbr > INT_MAX || nbr < INT_MIN)
	{
		ft_putendl_fd("input is too high or low", STDERR_FILENO);
		exit();
	}
	return (ft_lstnew(ft_atoi(nbr)));
}

/**
 * Initialising the given main arguments in a linked list. 
 * Converting from string to integer and checking for duplicates. 
 */
t_list	*init_stack_a(int32_t argc, char **argv)
{
	size_t	i;
	t_list	*node;
	t_list	*prev_node;
	t_list	*head;

	i = 1;
	head = init_node(argv, i++);
	prev_node = head;
	while (i < argc - 2)
	{
		node->content.value = init_node(argv, i++);
		prev_node->next = node;
		prev_node = node;
	}
	return (head);
}

// --93-94 00010101 0000-984 lasidfjasf lijf930 432138972348723508908345345789345789345785 -3487398743754893275439857349857 three "42 21" 

int32_t	main(int32_t argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = init_stack_a(argc, argv);
	stack_b = ft_lstnew(0);
}
