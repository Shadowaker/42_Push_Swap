/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:53:34 by dridolfo          #+#    #+#             */
/*   Updated: 2022/04/11 17:43:44 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ck_filter_3(t_stack *c, t_stack *d, char *s)
{
	int	res;

	res = 0;
	if (ft_strncmp("rr\n", s, 3) == 0)
	{
		ft_rr(c, d, 0);
		res = 1;
	}
	else if (ft_strncmp("rra\n", s, 4) == 0)
	{
		ft_rra(c, 0);
		res = 1;
	}
	else if (ft_strncmp("rrb\n", s, 4) == 0)
	{
		ft_rrb(d, 0);
		res = 1;
	}
	else if (ft_strncmp("rrr\n", s, 4) == 0)
	{
		ft_rrr(c, d, 0);
		res = 1;
	}
	return (res);
}

static int	ck_filter_2(t_stack *c, t_stack *d, char *s, int res)
{
	if (ft_strncmp("pa\n", s, 3) == 0)
	{
		ft_pa(c, d, 0);
		res = 1;
	}
	else if (ft_strncmp("pb\n", s, 3) == 0)
	{
		ft_pb(c, d, 0);
		res = 1;
	}
	else if (ft_strncmp("ra\n", s, 3) == 0)
	{
		ft_ra(c, 0);
		res = 1;
	}
	else if (ft_strncmp("rb\n", s, 3) == 0)
	{
		ft_rb(d, 1);
		res = 1;
	}
	else
		res = ck_filter_3(c, d, s);
	return (res);
}

int	ck_filter(t_stack *c, t_stack *d, char *s)
{
	int	res;

	res = 0;
	if (ft_strncmp("sa\n", s, 3) == 0)
	{
		ft_sa(c, 0);
		res = 1;
	}
	else if (ft_strncmp("sb\n", s, 3) == 0)
	{
		ft_sb(d, 0);
		res = 1;
	}
	else if (ft_strncmp("ss\n", s, 3) == 0)
	{
		ft_ss(c, d, 0);
		res = 1;
	}
	else
		res = ck_filter_2(c, d, s, res);
	return (res);
}
