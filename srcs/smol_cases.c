/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smol_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 03:43:24 by mialbert          #+#    #+#             */
/*   Updated: 2022/08/03 02:52:53 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Sorts numbers for pairs of 3. Possible numbers: 132 213 321 231 312
 * The first if statement checks for 213, 321 and 132, 
 * then I check for 231 or 312. 
 * 
 * 213 -> [sa] 					-> 123
 * 321 -> [sa] 	231 -> [rra]	-> 123
 * 132 -> [sa] 		312 -> [ra]	-> 123
 * 				231 -> [rra]	-> 123
 * 					312 -> [ra]	-> 123
 */
void	case_3(t_llist **stack_a)
{
	if (((((*stack_a)->content > (*stack_a)->next->content) && ((*stack_a)->content < (*stack_a)->next->next->content)) 
	||	(((*stack_a)->content > (*stack_a)->next->content) && ((*stack_a)->next->content > (*stack_a)->next->next->content))) 
	||	(((*stack_a)->content < (*stack_a)->next->content && (*stack_a)->content < (*stack_a)->next->next->content)))
		sa(stack_a, true);
	if (check_sorting(*stack_a))
		return ;
	if ((*stack_a)->content > (*stack_a)->next->content)
		ra(stack_a, true);
	else if ((*stack_a)->content < (*stack_a)->next->content)
		rra(stack_a, true);
}

/**
 * First I push two numbers to stack b, so I can use the same instructions
 * as case_3 to order the 3 numbers in stack_a. After this sorting the
 * remainding two numbers is ez. 
 */
void	case_5(t_llist **stack_a, t_llist **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	case_3(stack_a);
	pa(stack_a, stack_b);
	if ((*stack_a)->content > (*stack_a)->next->content)
		ra(stack_a, true);
	pa (stack_a, stack_b);
}
