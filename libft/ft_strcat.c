/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 05:36:21 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/24 02:34:28 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, char const *s2)
{
	size_t	index;
	size_t	index2;

	index = ft_strlen(s1);
	index2 = 0;
	while (s2[index2])
	{
		s1[index++] = s2[index2++];
	}
	s1[index] = '\0';
	return (s1);
}
