/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 23:51:03 by dsohn             #+#    #+#             */
/*   Updated: 2021/03/10 03:13:17 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

typedef struct s_stack
{
	int				*array;
	unsigned int	size;
	unsigned int	count;
	unsigned int	top;
	int				way;
}t_stack;

t_stack				*ft_stack_alloc(unsigned int size);
void				ft_stack_free(t_stack *stack);
void				ft_stack_swap(t_stack *stack);
int					ft_stack_push(t_stack *stack, int value);
int					ft_stack_pop(t_stack *stack);
int					ft_stack_top(t_stack *stack, int *value);
int					ft_stack_last_idx(t_stack *stack);
void				ft_stack_rotate(t_stack *stack);
void				ft_stack_rrotate(t_stack *stack);
int					ft_stack_check(t_stack *stack);
int					ft_stack_is_overlap(t_stack *s);

int					ft_stack_work(t_stack *a, t_stack *b, char *str);

#endif
