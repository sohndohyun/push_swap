NAME_C = checker
NAME_M = push_swap
FLAGS =	-Wall -Wextra -Werror
HEADER = -I. -I./libft/
CC =	gcc
SRCS =	ft_stack.c ft_stack2.c ft_stack3.c
OBJS = $(SRCS:.c=.o)

all: $(NAME_C) $(NAME_M)
$(NAME_C): $(OBJS)
	$(MAKE) -C ./libft
	cp ./libft/libft.a _libft.a
	$(CC) $(FLAGS) $(HEADER) checker_main.c _libft.a $^ -o $(NAME_C)
$(NAME_M): $(OBJS)
	$(MAKE) -C ./libft
	cp ./libft/libft.a _libft.a
	$(CC) $(FLAGS) $(HEADER) main.c _libft.a $^ -o $(NAME_M)

%.o: %.c
	$(CC) $(FLAGS) $(HEADER) -o $@ -c $<

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME_C)
	rm -f $(NAME_M)
	$(MAKE) -C ./libft fclean
	rm -f _libft.a
	
re: fclean all
