NAME_C = checker
FLAGS =	-Wall -Wextra -Werror
HEADER = -I. -I./libft/
CC =	gcc
SRCS_C =	checker_main.c ft_stack.c ft_stack2.c ft_stack3.c
OBJS_C =	$(SRCS_C:.c=.o)

all: $(NAME_C)
$(NAME_C): $(OBJS_C)
	$(MAKE) -C ./libft
	cp ./libft/libft.a _libft.a
	$(CC) $(FLAGS) $(HEADER) _libft.a $^ -o $(NAME_C)

%.o: %.c
	$(CC) $(FLAGS) $(HEADER) -o $@ -c $<

clean:
	rm -f $(OBJS_C)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME_C)
	$(MAKE) -C ./libft fclean
	rm -f _libft.a
	
re: fclean all