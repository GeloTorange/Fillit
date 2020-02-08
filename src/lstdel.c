/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 20:44:04 by rmaple            #+#    #+#             */
/*   Updated: 2020/02/01 19:02:30 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_fields(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int			lstdel(t_termino *list)
{
	t_termino	*tmp;

	while (list != NULL)
	{
		tmp = list;
		free_fields(list->termino);
		list = list->next;
		free(tmp);
	}
	list = NULL;
	return (0);
}

t_termino	*lstdel_t(t_termino *list)
{
	t_termino	*tmp;

	while (list != NULL)
	{
		tmp = list;
		free_fields(list->termino);
		list = list->next;
		free(tmp);
	}
	list = NULL;
	return (0);
}
