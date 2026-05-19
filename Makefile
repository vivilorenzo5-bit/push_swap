# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlourenc <vlourenc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/12 11:08:52 by roda-fon          #+#    #+#              #
#    Updated: 2026/05/19 12:37:53 by vlourenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM = rm -f

SRCS = main.c operations1.c operations2.c operations3.c \
       parsing.c tatic.c utils_algorithms.c \
       utils_main.c utils_parsing.c print.c 

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@echo "$(NAME) compiling..."
	@$(CC) $(CFLAGS) $(OBJS)
	@echo "$(NAME) compiled successfully."

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C clean
	@$(RM) $(OBJS)
	@echo "Object files ($(NAME)) removed."

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(NAME) removed."

re: fclean all

.PHONY: all clean fclean re