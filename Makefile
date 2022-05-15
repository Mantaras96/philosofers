# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amantara <amantara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 19:02:21 by albertmanta       #+#    #+#              #
#    Updated: 2022/05/15 19:30:50 by amantara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philosofers

SRC	=	main.c \
		utils.c \
		init_objs.c \
		validate_args.c \
		utils_time.c \
		philo_thread.c \
		error_and_free.c

OBJ	= $(addprefix objs/,$(SRC:.c=.o))

CC	=	gcc
CFLAGS	= -Wall -Wextra -Werror

objs/%.o:src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $^

all:	$(NAME)

$(NAME): $(OBJ) include/philosophers.h
	@$(CC) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf ./objs

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all re clean fclean
