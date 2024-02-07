NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = inc/
FOLDER = srcs/
OBJFOLDER = obj/
SRCS = main.c \
       algorithms/push_swap.c \
       algorithms/sort_small.c \
       operations/push_operation.c \
       operations/reverse_rotate_operation.c \
       operations/rotate_operation.c \
       operations/swap_operation.c \
       utils/checks.c \
       utils/errors.c \
       utils/ft_split.c \
       utils/linked_list.c \
       utils/set_node_values.c

OBJS = $(SRCS:%.c=$(OBJFOLDER)%.o)

$(OBJFOLDER)%.o: $(FOLDER)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	@rm -rf $(OBJFOLDER)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re