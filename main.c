/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:45:49 by dsohn             #+#    #+#             */
/*   Updated: 2021/03/10 03:31:02 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_stack.h"
#include <unistd.h>
#include <stdlib.h>

void	error_error(void)
{
	write(2, "Error!\n", 7);
	exit(1);
}

t_stack	*argv_stack(int argc, char **argv)
{
	int		i;
	t_stack	*stack;

	i = argc - 1;
	stack = ft_stack_alloc(argc - 1);
	if (stack == NULL)
		error_error();
	while (i > 0)
	{
		if (!ft_isdigit(*argv[i]))
			error_error();
		ft_stack_push(stack, ft_atoi(argv[i]));
		i--;
	}
	if (ft_stack_is_overlap(stack))
		error_error();
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
//	char	*line;

	if (argc < 2)
		return (1);
	a = argv_stack(argc, argv);
	b = ft_stack_alloc(a->size);
	if (!b)
		error_error();
	ft_stack_free(a);
	ft_stack_free(b);
	return (0);
}
