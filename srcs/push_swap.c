/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:47:03 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/27 02:19:19 by mialbert         ###   ########.fr       */
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
	t_llist	*smol;
	int32_t	lst_size;

	index = 0;
	lst = head;
	smol = head;
	lstset(head, -1, lst->index);
	lst_size = lstsize(head);
	while (index < lst_size)
	{
		while (lst->next != NULL)
		{
				printf("lst->next->content: %d, smol->content %d lst->next->index %d\n", lst->next->content, smol->content, lst->next->index);
			if (lst->next->content < smol->content && lst->next->index < 0)
			{
				smol = lst->next;
			}
			lst = lst->next;
		}
		printf("after loop smol->content: %d\n", smol->content);
		smol->index = index;
		printf("index: %d\n", index);
		printf("smol->index: %d\n", smol->index);
		lst = head;
		while (lst->next != NULL && lst->index >= 0)
			lst = lst->next;
		smol = lst;
		lst = head;
		index++;
		printf("index: %d\n", index);
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
