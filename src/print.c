/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:09:18 by torange           #+#    #+#             */
/*   Updated: 2020/01/22 22:58:40 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**dot_filler(char **tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			tab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (tab);
}

static char		**tabnew(int size)
{
	char	**tab;
	int		i;

	if (!(tab = (char **)malloc(sizeof(*tab) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(tab[i] = ft_strnew(size)))
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

static void		print_and_free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putendl(tab[i]);
		ft_strdel(&tab[i]);
		i++;
	}
	free_fields(tab);
}

void			to_fill_it(t_termino *ptr, int size)
{
	int		i;
	int		j;
	char	**tab;

	tab = tabnew(size);
	dot_filler(tab, size);
	while (ptr != NULL)
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (ptr->termino[i][j] == '#')
				{
					tab[ptr->x + i][ptr->y + j] = ptr->nbr;
				}
				j++;
			}
			i++;
		}
		ptr = ptr->next;
	}
	print_and_free_tab(tab, size);
}
