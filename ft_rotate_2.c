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

void	ft_rra(t_stack *a)
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
	}
}

void	ft_rrb(t_stack *b)
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
	}
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rra(a);
	ft_rrb(b);
}
