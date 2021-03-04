NAME = checker
FLAGS =	-Wall -Wextra -Werror
HEADER = -I. -I./libft/
CC =	gcc
SRCS =	main.c ft_stack.c ft_stack2.c
OBJS =	$(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(MAKE) -C ./libft bonus
	cp ./libft/libft.a _libft.a
	$(CC) $(FLAGS) $(HEADER) _libft.a $^ -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(HEADER) -o $@ -c $<

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean
	rm -f _libft.a
	
re: fclean all