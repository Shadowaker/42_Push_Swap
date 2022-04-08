/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:42:47 by dridolfo          #+#    #+#             */
/*   Updated: 2022/04/08 22:44:00 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Add a character to the start of a string.
*	Whithout deleting the first element of the string.*/

char	*ft_stradd(char *s, char c)
{
	char	*s1;
	int		i;

	s1 = malloc(ft_strlen(s) + 2);
	i = 0;
	s1[0] = c;
	while (s[i] != '\0')
	{
		s1[i + 1] = s[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
