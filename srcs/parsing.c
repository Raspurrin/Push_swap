/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:47:00 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/25 23:58:43 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The node is initialised with atoll because if an integer is given beyond the
 * regular integer range, then you would get some kind of garbage content when 
 * smashed into just 4 bytes. 
 * 11 to account of the case there is a + or - beforehand. 
 */
static int32_t	init_node(char *argv)
{
	size_t	i;
	int64_t	nbr;

	i = 0;
	while (*argv == '0')
		argv++;
	if (argv[0] == '+' || argv[0] == '-')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i++]))
			display_error("input contains something "
				"different than digits");
	}
	if (i <= 11)
	{
		nbr = ft_atoll(argv);
		if (nbr <= INT_MAX && nbr >= INT_MIN)
			return (nbr);
	}
	return (display_error("Input is too high or low"), false);
}

static bool	ft_lstcmp(t_llist *head, int32_t nbr)
{
	if (!head)
		return (false);
	while (head != NULL)
	{
		if (head->content == nbr)
			return (false);
		head = head->next;
	}
	return (true);
}

/**
 * Initialising the given main arguments in a linked list. 
 * Converting from string to integer and checking for duplicates.
 */
void	init_stack_a(t_llist *head, char **argv)
{
	size_t	i;
	int32_t	nbr;
	t_llist	*lst;

	i = 0;
	argv++;
	lst = head;
	while (*argv != NULL)
	{
		nbr = init_node(*argv++);
		if (!ft_lstcmp(head, nbr))
			display_error("Duplicates detected");
		lst->content = nbr;
		lst->next = lstnew(0);
		lst = lst->next;
	}
}

// 000005326 53535dfdf035 owisjfe 3845723942786558234766825466346363 ---35353 -366 +4363