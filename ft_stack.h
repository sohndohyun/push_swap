#ifndef circular_stack_h
#define circular_stack_h

typedef struct		s_stack
{
	int				*array;
	unsigned int	size;
	unsigned int	count;
	unsigned int	top;
	int				way;
}					t_stack;

t_stack				*ft_stack_alloc(unsigned int size);
void				ft_stack_free(t_stack *stack);
void				ft_stack_swap(t_stack *stack);
int					ft_stack_push(t_stack *stack, int value);
int					ft_stack_pop(t_stack *stack);
int					ft_stack_top(t_stack *stack, int *value);
void				ft_stack_rotate(t_stack *stack);
void				ft_stack_rrotate(t_stack *stack);
int					ft_stack_check(t_stack *stack);
void				ft_stack_debug(t_stack *stack, int fd);

#endif
