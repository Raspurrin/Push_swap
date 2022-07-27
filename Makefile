# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 15:41:31 by mialbert          #+#    #+#              #
#    Updated: 2022/07/27 03:57:00 by mialbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
NAME	= push_swap
CFLAGS	= -Wall -Werror -Wextra
HEADER	= -I includes -I libs/libft/srcs
LIBFT	= ./libs/libft/
DEBUG	= -fsanitize=address
SRCS	=	./srcs/instructions.c \
			./srcs/parsing.c \
			./srcs/indexing.c \
			./srcs/utils.c \
			./srcs/lst_functions.c

OBJS	= $(SRCS:.c=.o)

NC		:= \033[0m
RED 	:= \033[1;31m
B_GREEN	:= \033[1;32m
GREEN 	:= \033[0;32m
BLUE 	:= \033[0;34m
PURPLE	:= \033[0;35m

all: libft $(NAME)

%.o : %.c 
	@echo "$(B_GREEN)Compiling: $(GREEN)$(notdir $<) 🔨$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

libft:
	@echo "\n${BLUE}======== libft ========${NC}"
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(LIBFT) bonus


$(NAME): $(OBJS)
	@$(CC) $(BONUS) -g $(CFLAGS) $(HEADER) $(LIBFT)libft.a $(OBJS) $(DEBUG) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@echo "${RED} Removed ${NC} $(OBJS)"
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@echo "${RED} Removed ${NC} $(NAME)"
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all, libft, clean, fclean
