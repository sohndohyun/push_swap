/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 01:22:16 by dsohn             #+#    #+#             */
/*   Updated: 2021/03/08 02:50:47 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_stack.h"
#include <unistd.h>
#include <stdlib.h>

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	if (argc < 2)
		return (1);
	a = argv_stack(argc, argv);
	if (!(b = ft_stack_alloc(a->size)))
	{
		write(2, "Error!\n", 7);
		exit(1);
	}
	while ((ft_gnl(0, &line) > 0))
	{
		work_stack(a, b, line);
		free(line);
	}
	free(line);
	if (ft_stack_check(a) && b->count == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_stack_free(a);
	ft_stack_free(b);
	return (0);
}
