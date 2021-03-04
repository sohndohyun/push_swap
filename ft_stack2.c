/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 01:22:10 by dsohn             #+#    #+#             */
/*   Updated: 2021/03/05 01:22:11 by dsohn            ###   ########.fr       */
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

void		ft_stack_rotate(t_stack *stack)
{
	unsigned int last;

	if (stack->count == stack->size)
		stack->top = stack->top == 0 ? stack->size - 1 : stack->top - 1;
	else
	{
		last = (stack->top + stack->count) % stack->size;
		stack->array[last] = stack->array[stack->top];
		stack->top  = stack->top == 0 ? stack->size - 1 : stack->top - 1;
	}
}

void		ft_stack_rrotate(t_stack *stack)
{
	unsigned int last;

	if (stack->count == stack->size)
		stack->top = (stack->top + 1) % stack->size;
	else
	{
		last = (stack->top + stack->count) % stack->size;
		stack->top = (stack->top + 1) % stack->size;
		stack->array[stack->top] = stack->array[last];
	}
}

int			ft_stack_check(t_stack *stack)
{
	int i;
	int idx;
	int before;

	i = 0;
	before = -2147483648;
	while (i < stack->count)
	{
		idx = (i + stack->top) % stack->size;

	}
}

void		ft_stack_debug(t_stack *stack, int fd)
{
	int i;
	int idx;

	i = 0;
	
	while (i < stack->count)
	{
		idx = (i + stack->top) % stack->size;
		ft_putnbr_fd(stack->array[idx], fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
}
