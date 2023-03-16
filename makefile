# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 19:44:21 by pbergero          #+#    #+#              #
#    Updated: 2023/03/16 19:14:23 by pbergero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all bonus clean fclean re

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I./include -fsanitize=thread
RM		=	rm -f
MAKE	=	make

# Output file name
NAME	=	philosopher

# Sources are all .c files
SRCS	=	main.c \
			parsing.c \
			init.c \
			philo.c \
			print_philo.c \
			timer.c \
			utils.c \
			eating.c \
			terminate.c \

SRCS_DIR	=	src
# Objects are all .o files
OBJS_DIR	=	bin
OBJS	:= 	$(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))
LIBFT	=	libft/libft.a

#colors
GREEN	=	\033[38;5;46m
RESET	=	\033[0m


$(shell mkdir -p $(OBJS_DIR))
#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)
	

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< -MMD

# Generates output file
$(NAME): $(OBJS) 
	@echo "$(GREEN)creating $(NAME) files : $(RESET)"
	$(CC) $(CFLAGS) -o $@ $^

# Removes objects
clean:
	$(HIDE)$(RM) $(OBJS) $(OBJS:.o=.d) 

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)
	
# Removes objects and executables and remakes
re: fclean all

test: $(NAME)
	./philosopher 3 500 25 25 5

git:
	git add ./src/*.c ./include/*.h makefile
	git commit -m "auto commit"
	git push git@github.com:yup339/philosopher.git master
-include $(OBJ:.o=.d)