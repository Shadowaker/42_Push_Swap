/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_values.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:34:55 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/18 17:34:55 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Return the next greater int of an int n */
int	ft_upper(t_stack *arr, int n)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = ft_min(arr);
	while (i < arr->size)
	{
		if (arr->stack[i] > n)
		{
			tmp = arr->stack[i];
			break ;
		}
		i++;
	}
	while (i < arr->size)
	{
		if (arr->stack[i] > n && arr->stack[i] < tmp)
			tmp = arr->stack[i];
		i++;
	}
	return (tmp);
}

/* Return the next lower int of an int n */
int	ft_lower(t_stack *arr, int n)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < arr->size)
	{
		if (arr->stack[i] < n)
		{
			tmp = arr->stack[i];
			break ;
		}
		i++;
	}
	while (i < arr->size)
	{
		if (arr->stack[i] < n && arr->stack[i] > tmp)
			tmp = arr->stack[i];
		i++;
	}
	return (tmp);
}

/* Return the minimun value in array of ints*/
int	ft_min(t_stack *arr)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = arr->stack[0];
	while (i < arr->size)
	{
		if (arr->stack[i] < tmp)
			tmp = arr->stack[i];
		i++;
	}
	return (tmp);
}

/* Return the maximum value in array of ints*/
int	ft_max(t_stack *arr)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = arr->stack[0];
	while (i < arr->size)
	{
		if (arr->stack[i] > tmp)
			tmp = arr->stack[i];
		i++;
	}
	return (tmp);
}

/* Return index of passed number */
int	ft_return_index(t_stack *arr, int n)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < arr->size)
	{
		if (arr->stack[i] != n)
			j++;
		else
			return (j);
		i++;
	}
	return (-1);
}
