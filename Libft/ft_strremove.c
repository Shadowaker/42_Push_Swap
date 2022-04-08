/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:54:56 by dridolfo          #+#    #+#             */
/*   Updated: 2022/04/08 22:44:12 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Remove the first character to the start of the string.
*	Whithout deleting the first element of the string.*/

char	*ft_strremove(char	*s, int i)
{
	char	*s2;
	int		j;
	int		k;

	s2 = malloc(ft_strlen(s));
	j = 0;
	k = 0;
	while (s[j] != '\0')
	{
		if (j != i)
			s2[k] = s[j];
		k++;
		j++;
	}
	return (s2);
}
