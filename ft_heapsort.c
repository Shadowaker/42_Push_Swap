/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heapsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:42:13 by dridolfo          #+#    #+#             */
/*   Updated: 2022/04/09 17:31:41 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_advanced_algorithm(t_stack *a, t_stack *b)
{
	if (ft_issorted360(a) == 1)
	{
		if (ft_return_index(a, ft_min(a)) <= a->size / 2)
		{
			while (issorted(a) == 0)
				ft_ra(a, 1);
		}
		else
		{
			while (issorted(a) == 0)
				ft_rra(a, 1);
		}
		return ;
	}
	while (a->size > 3)
		ft_pb(a, b, 1);
	ft_basic_algorithm(a);
	ft_mind(a, b, 0);
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
