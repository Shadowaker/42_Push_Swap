/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:54:49 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/18 22:42:56 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putnbr(unsigned int n, char *base, unsigned int l)
{
	if (n >= l)
	{
		ft_putnbr(n / l, base, l);
		ft_putnbr(n % l, base, l);
	}
	else
		write(1, &base[n], 1);
}

void	show_stack(t_stack *arr, char *aname)
{
	int	i;
	int	tmp;

	i = 0;
	write(1, aname, ft_strlen(aname));
	write(1, "\n", 1);
	while (arr->size > i)
	{
		if (arr->stack[i] < 0)
		{
			write(1, "-", 1);
			tmp = arr->stack[i] * -1;
		}
		else
			tmp = arr->stack[i];
		ft_putnbr(tmp, "0123456789", 10);
		write(1, "\n", 1);
		i++;
	}
}

void	show_stacks(t_stack *a, t_stack *b)
{
	show_stack(a, "Stack A");
	show_stack(b, "Stack B");
}
