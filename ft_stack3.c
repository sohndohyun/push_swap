/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 02:43:30 by dsohn             #+#    #+#             */
/*   Updated: 2021/03/07 03:31:05 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "libft/libft.h"
#include <stdlib.h>

static void		work_stack2(t_stack *a, t_stack *b, char *str)
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
	{
		ft_putendl_fd("Error!", 2);
		exit(1);
	}
}

static void		work_stack0(t_stack *a, t_stack *b, char *str)
{
	int temp;

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
		work_stack2(a, b, str);
}

void			work_stack(t_stack *a, t_stack *b, char *str)
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
		work_stack0(a, b, str);
}

t_stack			*argv_stack(int argc, char **argv)
{
	int		i;
	t_stack	*stack;

	i = argc - 1;
	stack = ft_stack_alloc(argc - 1);
	if (stack == NULL)
	{
		ft_putendl_fd("Error!", 2);
		exit(1);
	}
	while (i > 0)
	{
		if (!ft_isdigit(*argv[i]))
		{
			ft_putendl_fd("Error!", 2);
			exit(1);
		}
		ft_stack_push(stack, ft_atoi(argv[i]));
		i--;
	}
	return (stack);
}