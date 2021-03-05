/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 01:22:10 by dsohn             #+#    #+#             */
/*   Updated: 2021/03/06 03:23:33 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <unistd.h>
#include "libft/libft.h"

int			ft_stack_top(t_stack *stack, int *value)
{
	if (stack->count == 0)
		return (0);
	*value = stack->array[stack->top];
	return (1);
}

int			ft_stack_last_idx(t_stack *stack)
{
	unsigned int cm;

	if (stack->count == 0)
		return (stack->top);
	cm = stack->count - 1;
	return (stack->top < cm ?
		stack->size - cm + stack->top : stack->top - cm);
}

void		ft_stack_rotate(t_stack *stack)
{
	unsigned int last;

	if (stack->count == stack->size)
		stack->top = stack->top == 0 ? stack->size - 1 : stack->top - 1;
	else
	{
		last = ft_stack_last_idx(stack);
		last = last == 0 ? stack->size - 1 : last - 1;
		stack->array[last] = stack->array[stack->top];
		stack->top = stack->top == 0 ? stack->size - 1 : stack->top - 1;
	}
}

void		ft_stack_rrotate(t_stack *stack)
{
	unsigned int last;

	if (stack->count == stack->size)
		stack->top = (stack->top + 1) % stack->size;
	else
	{
		last = ft_stack_last_idx(stack);
		stack->top = (stack->top + 1) % stack->size;
		stack->array[stack->top] = stack->array[last];
	}
}

int			ft_stack_check(t_stack *stack)
{
	unsigned int	i;
	int				idx;
	int				before;

	i = 0;
	before = 2147483647;
	idx = ft_stack_last_idx(stack);
	while (i < stack->count)
	{
		if (stack->array[idx] >= before)
			return (0);
		before = stack->array[idx];
		i++;
		idx = (idx + 1) % stack->size;
	}
	return (1);
}
