/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:00:55 by dridolfo          #+#    #+#             */
/*   Updated: 2022/04/09 18:36:45 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_checker(t_stack *a, t_stack *b, t_stack *c, t_stack *d)
{
	char	*s;
	int		res;

	printf("Hello\n");
	s = get_next_line(1);
	printf("Hello2\n");
	while (ft_strchr(s, 10) != '\0')
	{
		printf("Hello3\n");
		fflush(0);
		res = ck_filter(c, d, s);
		free(s);
		if (res != 1)
			error_handler(3);
		s = get_next_line(1);
		if (s == NULL)
			break ;
	}
	if (issorted(c) == 1 && d->size == 0 && issorted(a) == 1 && b->size == 0)
		write(1, "\n\033[32mOK!\033[0m\n", ft_strlen("\n\033[32mOK!\033[0m\n"));
	else
		write(1, "\n\033[91mKO!\033[0m\n", ft_strlen("\n\033[91mKO!\033[0m\n"));
}

static void	ft_free_it(t_stack a, t_stack b, t_stack c, t_stack d)
{
	free(a.arr);
	free(c.stack);
	free(d.stack);
	free(a.stack);
	free(b.stack);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_stack	c;
	t_stack	d;

	if (argc > 1)
	{
		a = ft_parser(argc, argv);
		c = ft_parser(argc, argv);
		if (a.size != -1)
		{
			b = create_it(a.size);
			d = create_it(c.size);
			if (a.size > 1 && (issorted(&a) == 0))
				sort_it(&a, &b);
			ft_checker(&a, &b, &c, &d);
			ft_free_it(a, b, c, d);
		}
		else
			error_handler(0);
	}
	else
		error_handler(1);
}
