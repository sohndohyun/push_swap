/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 02:43:30 by dsohn             #+#    #+#             */
/*   Updated: 2021/03/10 03:18:44 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

static int	work_stack2(t_stack *a, t_stack *b, char *str)
{
	if (ft_strcmp(str, "ra") == 0)
		ft_stack_rotate(a);
	else if (ft_strcmp(str, "rb") == 0)
		ft_stack_rotate(b);
	else if (ft_strcmp(str, "rr") == 0)
	{
		ft_stack_rotate(a);
		ft_stack_rotate(b);
	}
	else if (ft_strcmp(str, "rra") == 0)
		ft_stack_rrotate(a);
	else if (ft_strcmp(str, "rrb") == 0)
		ft_stack_rrotate(b);
	else if (ft_strcmp(str, "rrr") == 0)
	{
		ft_stack_rrotate(a);
		ft_stack_rrotate(b);
	}
	else
		return (0);
	return (1);
}

static int	work_stack0(t_stack *a, t_stack *b, char *str)
{
	int	temp;

	if (ft_strcmp(str, "pa") == 0)
	{
		if (ft_stack_top(b, &temp))
		{
			ft_stack_pop(b);
			ft_stack_push(a, temp);
		}
	}
	else if (ft_strcmp(str, "pb") == 0)
	{
		if (ft_stack_top(a, &temp))
		{
			ft_stack_pop(a);
			ft_stack_push(b, temp);
		}
	}
	else
		return (work_stack2(a, b, str));
	return (1);
}

int	ft_stack_work(t_stack *a, t_stack *b, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		ft_stack_swap(a);
	else if (ft_strcmp(str, "sb") == 0)
		ft_stack_swap(b);
	else if (ft_strcmp(str, "ss") == 0)
	{
		ft_stack_swap(a);
		ft_stack_swap(b);
	}
	else
		return (work_stack0(a, b, str));
	return (1);
}

int	ft_stack_is_overlap(t_stack *s)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < s->count)
	{
		j = i + 1;
		while (j < s->count)
		{
			if (s->array[i] == s->array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
