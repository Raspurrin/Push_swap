/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:43:34 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/19 01:19:22 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdint.h>
# include <stdbool.h>
# include <limits.h>
# include "../libs/libft/includes/libft.h"

typedef struct s_num
{
	int32_t	value;
	int32_t	index;
}	t_num;

t_list	*init_stack_a(char **argv);
void	display_error(char *error_msg);

#endif





















// printf("hiello %s I am %d years old. And this is %s", name, age, adjective)

// function(char c)
// {
// 	if (c == 's')
// 		ft_putstr_fd(va_arg(argp, char *));
// 	if (c == 'd')
// 		ft_putnbr_fd(va_arg(argp, int32_t););
// }

// int32_t ft_printf(char *str, ...)
// {
// 	va_list argp;

// 	va_start(argp, str);
	
// 	while (str[i])
// 	{
// 		if (str[i] == '%')
// 			function(str[i + 1]);
// 		else 
// 			ft_putchar_fd(str[i], STDOUT_FILENO);
// 	}

// 	va_end(argp);
// }

// char name[] = "Djaisin"
// int32_t age = 27;
// char adjective[] = "depressing"