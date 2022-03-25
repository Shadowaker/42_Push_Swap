/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:32:20 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/18 17:32:20 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *a, t_stack *b)
{
	int	i;

	if (b->size > 0)
	{
		i = a->size;
		while (i--)
			a->stack[i + 1] = a->stack[i];
		a->stack[0] = b->stack[0];
		a->size += 1;
		i = 1;
		while (i < b->size)
		{
			b->stack[i - 1] = b->stack[i];
			i++;
		}
		b->size -= 1;
	}
}

void	ft_pb(t_stack *a, t_stack *b)
{
	int	i;

	if (a->size > 0)
	{
		i = b->size;
		while (i--)
			b->stack[i + 1] = b->stack[i];
		b->stack[0] = a->stack[0];
		b->size += 1;
		i = 1;
		while (i < a->size)
		{
			a->stack[i - 1] = a->stack[i];
			i++;
		}
		a->size -= 1;
	}
}

void	ft_ra(t_stack *a)
{
	int		i;
	int		tmp;

	if (a->size > 1)
	{
		tmp = a->stack[0];
		i = 1;
		while (i < a->size)
		{
			a->stack[i - 1] = a->stack[i];
			i++;
		}
		a->stack[i - 1] = tmp;
	}
}

void	ft_rb(t_stack *b)
{
	int		i;
	int		tmp;

	if (b->size > 1)
	{
		tmp = b->stack[0];
		i = 1;
		while (i < b->size)
		{
			b->stack[i - 1] = b->stack[i];
			i++;
		}
		b->stack[i - 1] = tmp;
	}
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a);
	ft_rb(b);
}
