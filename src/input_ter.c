/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_ter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:04:18 by torange           #+#    #+#             */
/*   Updated: 2020/01/23 19:37:23 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char		**ft_split(char *str)
{
	int		i;
	int		j;
	char	**s;

	s = NULL;
	i = 0;
	if (!(s = (char **)malloc(sizeof(char *) * 5)) ||
			str[20] == '.' || str[20] == '#' || str[4] != '\n')
		return (NULL);
	while (*str)
	{
		j = 0;
		if (!(s[i] = (char *)malloc(sizeof(char) * 5)))
			return (NULL);
		if (i < 4)
			while (*str != '\n' && *str)
				s[i][j++] = *str++;
		else
			str++;
		while (*str == '\n')
			str++;
		s[i++][j] = '\0';
	}
	s[i] = NULL;
	return (s);
}

t_termino	*terminos_input(char *filename)
{
	int			file;
	t_termino	*begin;
	t_termino	*head;
	char		cha[21];

	if (!((file = open(filename, O_RDONLY)) < 0))
		if (read(file, &cha, 21))
		{
			if (ch(ft_split(cha)) == 1)
			{
				begin = initlist(ft_split(cha));
				head = begin;
				while (read(file, &cha, 21))
				{
					if (ch(ft_split(cha)) == 1)
						ft_list_push_back(&begin, ft_split(cha));
					else
						return (lstdel_t(head));
					begin = begin->next;
				}
				close(file);
				return (head);
			}
		}
	return (NULL);
}
