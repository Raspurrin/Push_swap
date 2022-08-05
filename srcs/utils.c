/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:51:13 by mialbert          #+#    #+#             */
/*   Updated: 2022/08/05 02:25:36 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display_error(char *error_msg, t_llist *stack_a)
{
	lstclear(&stack_a);
	ft_printf_fd(STDERR_FILENO, "%s\n", error_msg);
	exit(EXIT_FAILURE);
}
