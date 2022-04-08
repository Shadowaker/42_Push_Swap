/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heapsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:42:13 by dridolfo          #+#    #+#             */
/*   Updated: 2022/04/08 15:11:00 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_heapsort(t_stack *a, t_stack *b)
{
	int	x;
	int	ind;

	x = ft_min(a);
	ind = ft_return_index(a, x);
	if (ind >= a->size / 2)
		ft_push_down(a, a->size - ind);
	else
		ft_push_up(a, ind);
	if (issorted(a) == 0)
		ft_pb(a, b);
}

void	ft_op(t_stack *a, t_stack *b)
{
	int	off;

	off = a->size / 2;
	while (a->size > off)
	{
		if (issorted(a) == 0)
			ft_heapsort(a, b);
		else
			break ;
	}
	while (b->size > 0)
		ft_pa(a, b);
}

void	ft_basic_algorithm(t_stack *a)
{
	if (ft_return_index(a, ft_min(a)) == 0
		&& ft_return_index(a, ft_max(a)) == 1)
	{
		ft_sa(a, 1);
		ft_ra(a, 1);
	}
	else if (ft_return_index(a, ft_min(a)) == 1
		&& ft_return_index(a, ft_max(a)) == 2)
		ft_sa(a, 1);
	else if (ft_return_index(a, ft_min(a)) == 2
		&& ft_return_index(a, ft_max(a)) == 1)
		ft_rra(a, 1);
	else if (ft_return_index(a, ft_min(a)) == 1
		&& ft_return_index(a, ft_max(a)) == 0)
		ft_ra(a, 1);
	else if (ft_return_index(a, ft_min(a)) == 2
		&& ft_return_index(a, ft_max(a)) == 0)
	{
		ft_sa(a, 1);
		ft_rra(a, 1);
	}
}
