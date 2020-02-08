/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:41:52 by torange           #+#    #+#             */
/*   Updated: 2020/01/23 19:46:53 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	size_tab(int nb)
{
	int	size;

	nb = nb * 4;
	size = nb;
	while ((size = ft_sqrt(size)) == -1)
	{
		nb++;
		size = nb;
	}
	return (size);
}

int			main(int argc, char **argv)
{
	int			i;
	int			nb;
	int			valid;
	t_termino	*list;

	valid = 0;
	nb = -1;
	if (argc != 2)
	{
		ft_putendl("usage: fillit input_file");
		return (0);
	}
	if ((list = terminos_input(argv[1])) != NULL)
	{
		if (((i = count_ter(list)) < 27) && (count_n(argv[1], i)) == 1)
		{
			nb = size_tab(i);
			while (!valid)
				valid = backtrack_tetr(list, list, nb++);
			to_fill_it(list, --nb);
			return (lstdel(list));
		}
	}
	ft_putendl("error");
	return (lstdel(list));
}
