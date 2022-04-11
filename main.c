/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:22:43 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/18 17:22:43 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc > 1)
	{
		a = ft_parser(argc, argv);
		if (a.size != -1)
		{
			b = create_it(a.size);
			if (a.size > 1 && (issorted(&a) == 0))
				sort_it(&a, &b);
			free(a.arr);
			free(a.stack);
			free(b.stack);
		}
		else
			error_handler(0);
	}
	else
		error_handler(-1);
}
