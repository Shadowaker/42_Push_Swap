/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:34:48 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/18 17:34:48 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sa(t_stack *a, int bool)
{
	if (a->size > 1)
	{
		ft_swap(&a->stack[0], &a->stack[1]);
		if (bool == 1)
			write(1, "sa\n", ft_strlen("sa\n"));
	}
}

void	ft_sb(t_stack *b, int bool)
{
	if (b->size > 1)
	{
		ft_swap(&b->stack[0], &b->stack[1]);
		if (bool == 1)
			write(1, "sb\n", ft_strlen("sb\n"));
	}
}

void	ft_ss(t_stack *a, t_stack *b, int bool)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	if (bool == 1)
		write(1, "ss\n", ft_strlen("ss\n"));
}
