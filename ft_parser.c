/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:26:48 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/18 17:26:48 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_validator(t_stack arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr.size)
	{
		j = i - 1;
		while (j > -1)
		{
			if (arr.stack[i] == arr.stack[j])
			{
				return (1);
			}
			j--;
		}
		i++;
	}
	return (0);
}

static int	*stack_init(int size, char **aa, int asize)
{
	int		i;
	int		j;
	char	**mat;
	int		*res;
	int		k;

	res = (int *) malloc(sizeof(int) * asize);
	if (!res)
		error_handler(2);
	i = 1;
	k = 0;
	while (i < size)
	{
		j = 0;
		mat = ft_split(aa[i], ' ');
		while (mat[j] != 0)
		{
			res[k] = ft_atoi(mat[j]);
			k++;
			free(mat[j++]);
		}
		free(mat);
		i++;
	}
	return (res);
}

static int	ft_checker(int size, char **aa)
{
	char	**mat;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	while (i < size)
	{
		mat = ft_split(aa[i], ' ');
		j = 0;
		while (mat[j])
		{
			if (ft_isint(mat[j]) == 1)
				k++;
			else
				return (-1);
			free(mat[j]);
			j++;
		}
		free(mat);
		i++;
	}
	return (k);
}

t_stack	ft_parser(int size, char **aa)
{
	t_stack		arr;

	arr.size = 0;
	arr.chunk_size = 0;
	arr.pos_a = 0;
	arr.pos_b = 0;
	if (size > 0)
	{
		arr.size = ft_checker(size, aa);
		if ((arr.size != -1))
		{
			arr.stack = stack_init(size, aa, arr.size);
			arr.arr = calloc(arr.size + 1, sizeof(int));
			if (!arr.arr)
				error_handler(2);
			if (ft_validator(arr) == 1)
			{
				arr.size = -1;
				return (arr);
			}
		}
	}
	else
		arr.size = -1;
	return (arr);
}
