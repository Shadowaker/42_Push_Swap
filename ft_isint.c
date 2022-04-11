/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:30:55 by dridolfo          #+#    #+#             */
/*   Updated: 2022/04/11 18:12:02 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	more_max(char *c, int n)
{
	int			i;
	long int	j;
	char		*s;

	i = 1;
	s = malloc(sizeof(char) * 2);
	s[0] = c[0];
	s[1] = '\0';
	j = ft_atoi(s);
	while (i <= n)
	{
		j *= 10;
		s[0] = c[i];
		j += ft_atoi(s);
		i++;
		if (j < -2147483648 || j > 2147483647)
			return (0);
	}
	free(s);
	return (1);
}

int	ft_isint(char *c)
{
	int			s;
	int			i;

	s = 1;
	i = 0;
	if (c[0] == '-' || c[0] == '+')
	{
		if (c[0] == '-')
			s *= -1;
		i++;
	}
	if (c[i] == '\0')
		return (0);
	while (c[i] != '\0')
	{
		if (ft_isdigit(c[i]) == 0 || more_max(c, i) == 0)
			return (0);
		i++;
	}
	return (1);
}
