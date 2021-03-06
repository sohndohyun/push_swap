/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 01:22:16 by dsohn             #+#    #+#             */
/*   Updated: 2021/03/07 03:34:29 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_stack.h"
#include <unistd.h>
#include <stdlib.h>

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
			ft_putnbr_fd(a->array[aa = (aa ? (aa - 1) : a->size - 1)], 1);
		else
			ft_putstr_fd(" ", 1);
		ft_putstr_fd("   ", 1);
		if (i < b->count)
			ft_putnbr_fd(b->array[bb = (bb ? (bb - 1) : b->size - 1)], 1);
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
	a = argv_stack(argc, argv);
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
