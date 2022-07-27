/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:43:34 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/27 03:57:40 by mialbert         ###   ########.fr       */
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
void	lstadd_back(t_llist **lst, t_llist *new);

// Linked list functions:
t_llist	*lstlast(t_llist *lst);
t_llist	*lstnew(int32_t nbr);
void	lstset(t_llist *lst, int32_t nbr);

#endif
