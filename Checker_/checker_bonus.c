/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:00:55 by dridolfo          #+#    #+#             */
/*   Updated: 2022/04/11 18:22:08 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_checker(t_stack *c, t_stack *d)
{
	char	*s;
	int		res;

	s = get_next_line(0);
	while (s)
	{
		res = ck_filter(c, d, s);
		free(s);
		if (res != 1)
			error_handler(3);
		s = get_next_line(0);
		if (s == NULL)
			break ;
	}
	if (issorted(c) == 1 && d->size == 0)
		write(1, "\033[32mOK\033[0m\n", ft_strlen("\033[32mOK\033[0m\n"));
	else
		write(1, "\033[91mKO\033[0m\n", ft_strlen("\033[91mKO\033[0m\n"));
}

static void	ft_free_it(t_stack c, t_stack d)
{
	free(c.arr);
	free(c.stack);
	free(d.stack);
}

int	main(int argc, char **argv)
{
	t_stack	c;
	t_stack	d;

	if (argc > 1)
	{
		c = ft_parser(argc, argv);
		if (c.size != -1)
		{
			d = create_it(c.size);
			ft_checker(&c, &d);
			ft_free_it(c, d);
		}
		else
			error_handler(0);
	}
	else
		error_handler(-1);
}
