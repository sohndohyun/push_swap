/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 01:22:05 by dsohn             #+#    #+#             */
/*   Updated: 2021/03/08 01:33:48 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <stdlib.h>

t_stack			*ft_stack_alloc(unsigned int size)
{
	t_stack	*temp;

	if (size == 0)
		return (NULL);
	if (!(temp = malloc(sizeof(t_stack))))
		return (NULL);
	if (!(temp->array = malloc(sizeof(int) * size)))
	{
		free(temp);
		return (NULL);
	}
	temp->size = size;
	temp->top = temp->size - 1;
	temp->way = -1;
	temp->count = 0;
	return (temp);
}

void			ft_stack_free(t_stack *stack)
{
	free(stack->array);
	free(stack);
}

void			ft_stack_swap(t_stack *stack)
{
	int				temp;
	unsigned int	next;

	next = stack->top == 0 ? stack->size - 1 : stack->top - 1;
	temp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[next];
	stack->array[next] = temp;
}

int				ft_stack_push(t_stack *stack, int value)
{
	if (stack->count == stack->size)
		return (0);
	stack->top = (stack->top + 1) % stack->size;
	stack->array[stack->top] = value;
	stack->count++;
	return (1);
}

int				ft_stack_pop(t_stack *stack)
{
	if (stack->count == 0)
		return (0);
	stack->top = stack->top == 0 ? stack->size - 1 : stack->top - 1;
	stack->count--;
	return (1);
}
