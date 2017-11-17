/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfilecontent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 06:10:36 by adeletan          #+#    #+#             */
/*   Updated: 2017/09/29 06:21:08 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_getfilecontent(char *filename)
{
	char	*line;
	char	**tab;
	int		i;
	int		fd;

	i = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &line) && ++i)
	{
		if (line[0] == '\0' && (i = 0) + 1)
			break ;
		ft_strdel(&line);
	}
	if (i == 0 || !(tab = (char**)ft_memalloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		tab[i++] = ft_strdup(line);
		ft_strdel(&line);
	}
	return (tab);
}
