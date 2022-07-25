/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:47:03 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/26 01:06:04 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * First you need to get the smallest number,
 * remember what the smallest number is, 
 * increase the index and check what the next smallest number is, while
 * being bigger than the previous smallest. 
 */
void	get_indexed(t_llist *head)
{
	t_llist	*lst;
	int32_t	index;
	int32_t	smallest;
	int32_t	lst_size;

	index = 0;
	lst = head;
	lst_size = lstsize(head);
	smallest = lst->content;
	while (lst->next != NULL)
	{
		printf("lst->content: %d lst->next->content %d\n", lst->content, lst->next->content);
		if (lst->content < smallest)
			smallest = lst->content;
		lst = lst->next;
	}
	while (index < lst_size)
	{
		lst = head;
		printf("smallest: %d\n", smallest);
		while (lst->next != NULL)
		{
			// printf("test lst->content: %d\n", lst->content);
			if (lst->content < lst->next->content && lst->content > smallest)
			{
				smallest = lst->content;
				lst->index = index;
				printf("lst->index: %d, lst->content: %d\n", lst->index, lst->content);
			}
			lst = lst->next;
		}
		index++;
	}
}

int32_t	main(int32_t argc, char **argv)
{
	t_llist	*stack_a;
	t_llist	*stack_b;

	argc = 0;
	stack_a = ft_calloc(1, sizeof(t_list));
	stack_b = ft_calloc(1, sizeof(t_list));
	init_stack_a(stack_a, argv);
	ft_lstprint_fd(stack_a, 'd', STDOUT_FILENO);
	get_indexed(stack_a);
	return (EXIT_SUCCESS);
}
