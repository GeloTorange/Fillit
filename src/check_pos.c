/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 13:32:14 by torange           #+#    #+#             */
/*   Updated: 2019/12/26 22:07:14 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_pos3(int x, int y, t_termino *current)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (current->termino[i][j] == '#')
			{
				if ((current->x + i == x)
						&& (current->y + j == y))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_pos(t_termino *tetr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetr->termino[i][j] == '#')
				if ((i + tetr->x) >= size || (j + tetr->y) >= size
						|| (i + tetr->x) < 0 || (j + tetr->y) < 0)
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_pos2(t_termino *start, t_termino *tetr)
{
	int			i;
	int			j;
	t_termino	*current;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetr->termino[i][j] == '#')
			{
				current = start;
				while (current->nbr != tetr->nbr)
				{
					if (!(check_pos3(tetr->x + i, tetr->y + j, current)))
						return (0);
					current = current->next;
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int			backtrack_tetr(t_termino *start, t_termino *tetr, int size)
{
	int	i;
	int	j;

	i = -3;
	while (i < size)
	{
		j = -3;
		while (j < size)
		{
			tetr->x = i;
			tetr->y = j;
			if (check_pos(tetr, size) == 1
					&& check_pos2(start, tetr) == 1)
			{
				if ((tetr->next) == NULL)
					return (1);
				if ((backtrack_tetr(start, tetr->next, size)) == 1)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
