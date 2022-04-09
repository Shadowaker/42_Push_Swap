/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:24:32 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/18 17:24:32 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_down(t_stack *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_rra(arr, 1);
		i++;
	}
}

void	ft_push_up(t_stack *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_ra(arr, 1);
		i++;
	}
}

void	ft_push_both_up(t_stack *a, t_stack *b, int off)
{
	int	i;

	i = 0;
	while (i < off)
	{
		ft_rr(a, b, 1);
		i++;
	}
}

void	ft_push_both_down(t_stack *a, t_stack *b, int off, int o)
{
	int	i;
	int	noff;

	i = 0;
	if (o == 0)
		noff = b->size - off;
	else
		noff = a->size - off;
	while (i <= noff)
	{
		ft_rrr(a, b, 1);
		i++;
	}
}
