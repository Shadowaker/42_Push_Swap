/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:33:27 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/18 17:33:27 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a, int bool)
{
	int	i;
	int	tmp;

	if (a->size > 1)
	{
		tmp = a->stack[a->size - 1];
		i = a->size - 1;
		while (i--)
			a->stack[i + 1] = a->stack[i];
		a->stack[0] = tmp;
		if (bool == 1)
			write(1, "rra\n", ft_strlen("rra\n"));
	}
}

void	ft_rrb(t_stack *b, int bool)
{
	int	i;
	int	tmp;

	if (b->size > 1)
	{
		tmp = b->stack[b->size - 1];
		i = b->size - 1;
		while (i--)
			b->stack[i + 1] = b->stack[i];
		b->stack[0] = tmp;
		if (bool == 1)
			write(1, "rrb\n", ft_strlen("rrb\n"));
	}
}

void	ft_rrr(t_stack *a, t_stack *b, int bool)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	if (bool == 1)
		write(1, "rrr\n", ft_strlen("rrr\n"));
}
