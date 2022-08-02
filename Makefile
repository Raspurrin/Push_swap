# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 15:41:31 by mialbert          #+#    #+#              #
#    Updated: 2022/08/02 20:48:35 by mialbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
NAME	= push_swap
CFLAGS	= -Wall -Werror -Wextra -g
HEADER	= -I includes -I libs/libft/srcs
LIBFT	= ./libs/libft/
DEBUG	= -fsanitize=address
SRCS	=	./srcs/instructions/push.c \
			./srcs/instructions/reverse.c \
			./srcs/instructions/rotate.c \
			./srcs/instructions/swap.c \
			./srcs/parsing.c \
			./srcs/indexing.c \
			./srcs/utils.c \
			./srcs/lst_functions.c \
			./srcs/main.c \
			./srcs/radix.c \
			./srcs/smol_cases.c

OBJS	= $(SRCS:.c=.o)

NC		:= \033[0m
B_RED	:= \033[1;31m
RED 	:= \033[0;31m
B_GREEN	:= \033[1;32m
GREEN 	:= \033[0;32m
B_BLUE 	:= \033[1;34m
BLUE 	:= \033[0;34m
PURPLE	:= \033[0;35m

SUBM_STATE := $(shell find libs/libft -type f)

# to automatically initialize the submodules
ifeq ($(SUBM_STATE),)
SUBM_FLAG	= submodule
else 
SUBM_FLAG	= 
endif

all: $(SUBM_FLAG) libft banner $(NAME)

submodule: 
	@git submodule init 
	@git submodule update

%.o : %.c 
	@echo "$(B_BLUE)Compiling: $(BLUE)$(notdir $<) 🔨$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

libft:
	@echo "\n${BLUE}======== libft ========${NC}"
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(LIBFT) bonus

banner:
	@echo "\n${PURPLE}======== push_swap ========${NC}"
	@say Its red ix baby

$(NAME): banner $(OBJS)
	@$(CC) $(OBJS) -g $(CFLAGS) $(HEADER) $(LIBFT)libft.a $(DEBUG) -o $(NAME)
	@say lets fucking go

clean:
	@rm -f $(OBJS)
	@echo "${B_RED}🧹 Cleaning: ${RED} push_swap object files $(NC)"
	@$(MAKE) -C $(LIBFT) fclean

fclean: clean
	@rm -f $(NAME)
	@echo "${B_RED}🧹 Cleaning: ${RED} $(NAME)$(NC)"

re: fclean all

.PHONY: all, libft, clean, fclean push_swap, submodule, print
