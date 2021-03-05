/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 01:22:16 by dsohn             #+#    #+#             */
/*   Updated: 2021/03/06 03:19:50 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_stack.h"
#include <unistd.h>
#include <stdlib.h>

t_stack		*make_stack(int argc, char **argv)
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

void		work_stack2(t_stack *a, t_stack *b, char *str)
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

void		work_stack(t_stack *a, t_stack *b, char *str)
{
	int temp;

	if (ft_strcmp(str, "sa") == 0)
		ft_stack_swap(a);
	else if (ft_strcmp(str, "sb") == 0)
		ft_stack_swap(b);
	else if (ft_strcmp(str, "ss") == 0)
	{
		ft_stack_swap(a);
		ft_stack_swap(b);
	}
	else if (ft_strcmp(str, "pa") == 0)
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

void		print_stack(t_stack *a, t_stack *b)
{
	unsigned int i;
	unsigned int aa;
	unsigned int bb;

	i = 0;
	aa = a->top + 1;
	bb = b->top + 1;
	while (i < a->size)
	{
		if (i < a->count)
			ft_putnbr_fd(a->array[aa = ((aa - 1) % a->size)], 1);
		else
			ft_putstr_fd(" ", 1);
		ft_putstr_fd("   ", 1);
		if (i < b->count)
			ft_putnbr_fd(b->array[bb = ((bb - 1) % b->size)], 1);
		else
			ft_putstr_fd(" ", 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	if (argc < 2)
		return (1);
	a = make_stack(argc, argv);
	b = ft_stack_alloc(a->size);
	print_stack(a, b);
	while ((ft_gnl(0, &line) > 0))
	{
		work_stack(a, b, line);
		print_stack(a, b);
		free(line);
	}
	free(line);
	if (ft_stack_check(a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	print_stack(a, b);
	ft_stack_free(a);
	ft_stack_free(b);
	return (0);
}
