/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:43:34 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/29 01:49:34 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdint.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include "../libs/libft/includes/libft.h"

typedef struct s_llist
{
	int32_t			content;
	int32_t			index;
	struct s_llist	*next;
}	t_llist;

void	indexing(t_llist *head);
void	display_error(char *error_msg);
void	init_stack_a(t_llist *head, char **argv);
bool	check_sorting(t_llist *stack_a);
void	back_to_a(t_llist *stack_a, t_llist *stack_b);
void	push_to_b(t_llist *stack_a, t_llist *stack_b, size_t i);
void	radix(t_llist *stack_a, t_llist *stack_b);


// Linked list functions:
t_llist	*lstlast(t_llist *lst);
t_llist	*lstnew(int32_t nbr);
void	lstset(t_llist *lst, int32_t nbr);
void	lstadd_back(t_llist **lst, t_llist *new);

// instructions: 
void	sa(t_llist **stack_a, bool print);
void	sb(t_llist **stack_b, bool print);
void	ss(t_llist **stack_a, t_llist **stack_b);
void	pa(t_llist **stack_a, t_llist **stack_b);
void	pb(t_llist **stack_a, t_llist **stack_b);
void	ra(t_llist **stack_a, bool print);
void	rb(t_llist **stack_b, bool print);
void	rr(t_llist **stack_a, t_llist **stack_b);
void	rra(t_llist **stack_a, bool print);
void	rrb(t_llist **stack_b, bool print);
void	rrr(t_llist **stack_a, t_llist **stack_b);
#endif
