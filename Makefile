# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlourenc <vlourenc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/12 11:08:52 by roda-fon          #+#    #+#              #
#    Updated: 2026/05/19 13:26:45 by vlourenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM = rm -f

SRCS_DIR = srcs
ALGO_DIR = algorithms
LIBFT_DIR = libft
PRINTFD_DIR = printfd

SRC_FILES = $(SRCS_DIR)/main.c \
			$(SRCS_DIR)/operations1.c \
			$(SRCS_DIR)/operations2.c \
			$(SRCS_DIR)/operations3.c \
			$(SRCS_DIR)/parsing.c \
			$(SRCS_DIR)/print.c \
			$(SRCS_DIR)/tatic.c \
			$(SRCS_DIR)/utils_main.c \
			$(SRCS_DIR)/utils_parsing.c \

ALGO_FILES = $(ALGO_DIR)/simple_algorithm.c \
			 $(ALGO_DIR)/medium_algorithm.c \
			 $(ALGO_DIR)/complex_algorithm.c \

LIBFT_FILES = $(LIBFT_DIR)/ft_split.c \
			  $(LIBFT_DIR)/ft_strncmp.c \

PRINTFD_FILES = $(PRINTFD_DIR)/ft_printfd_digits.c \
				$(PRINTFD_DIR)/ft_printfd_utils.c \
				$(PRINTFD_DIR)/ft_printfd.c \

SRCS = $(SRC_FILES) $(ALGO_FILES) $(LIBFT_FILES) $(PRINTFD_FILES)

OBJS = $(SRCS:.c=.o)

GREEN       = \033[0;32m
YELLOW      = \033[0;33m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compilando o executável $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Push_swap compilado com sucesso! 🚀$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "$(YELLOW)Object files ($(NAME)) removed.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)Executavel $(NAME) removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re