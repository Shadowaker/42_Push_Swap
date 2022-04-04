/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:22:36 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/18 17:22:36 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include "Libft/libft.h"

typedef struct s_stack
{
	int	*stack;
	int	size;
	int	*arr;
	int	chunk_size;
	int	offset;
	int	pos_a;
	int	pos_b;
}	t_stack;

void	show_stacks(t_stack *a, t_stack *b);
void	show_stack(t_stack *arr, char *aname);

void	ft_swap(int *a, int *b);
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);
void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);

void	ft_push_down(t_stack *arr, int n);
void	ft_push_up(t_stack *arr, int n);
void	ft_op(t_stack *a, t_stack *b);
void	ft_heapsort(t_stack *a, t_stack *b);

t_stack	ft_parser(int size, char **aa);
t_stack	create_it(int size);
int		issorted(t_stack *arr);
int		ft_upper(t_stack *arr, int n);
int		ft_lower(t_stack *arr, int n);
int		ft_min(t_stack *arr);
int		ft_max(t_stack *arr);
int		ft_isint(char *c);
int		ft_return_index(t_stack *arr, int n);
int		ft_count(t_stack *arr, int start);
int		ft_upperpart(t_stack *arr, int min);
int		ft_downpart(t_stack *arr, int min);

void	ft_mind(t_stack *a, t_stack *b);
void	ft_push_both_up(t_stack *a, t_stack *b, int off);
void	ft_push_both_down(t_stack *a, t_stack *b, int off, int o);
void	ft_pushinit(t_stack *a, t_stack *b);
int		ft_sigma(t_stack *a, t_stack *b, int min_a, int min_b);
void	ft_o_set(t_stack *a, t_stack *b, int o);
void	ft_o_set_a(t_stack *a);
int		ft_check(t_stack *a, t_stack *b, int i);
void	ft_lis(t_stack *a, t_stack *b);
void	confront(t_stack *a);

void	ft_optimal(t_stack *a, t_stack *b);
int		ft_issorted360(t_stack *a);
int		*balloc(int size, int val);
int		val_id(t_stack *a);

#endif
