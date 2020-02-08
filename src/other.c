/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:43:43 by torange           #+#    #+#             */
/*   Updated: 2020/01/04 18:26:15 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_sqrt(int nb)
{
	int	i;
	int	a;
	int	n;

	i = 0;
	n = 1;
	a = 0;
	while (a != nb)
	{
		if (i > 46340 || nb >= 2147483647)
			return (0);
		a = a + n;
		n = n + 2;
		i++;
	}
	return (i);
}

int	count_ter(t_termino *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int	count_n(char *filename, int i)
{
	int		file;
	char	character;
	int		count;

	count = 0;
	if ((file = open(filename, O_RDONLY)) < 0)
		return (0);
	while (read(file, &character, 1))
	{
		if (character == '\n')
			count++;
	}
	close(file);
	if ((count + 1) == (i * 5))
		return (1);
	return (0);
}
