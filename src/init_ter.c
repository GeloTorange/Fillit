/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:48:08 by torange           #+#    #+#             */
/*   Updated: 2020/01/22 22:58:58 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char					g_nb = 'A';

t_termino		*initlist(char **data)
{
	t_termino	*begin;

	if (!(begin = (t_termino*)malloc(sizeof(t_termino))))
		return (NULL);
	begin->termino = data;
	begin->x = -3;
	begin->y = -3;
	begin->nbr = g_nb;
	g_nb++;
	begin->next = NULL;
	return (begin);
}

void			ft_list_push_back_alt(t_termino *list, char **data)
{
	if (list->next == NULL)
		list->next = initlist(data);
	else
		ft_list_push_back_alt(list->next, data);
}

void			ft_list_push_back(t_termino **begin_list, char **data)
{
	if (!*begin_list)
		*begin_list = initlist(data);
	else
		ft_list_push_back_alt(*begin_list, data);
}

t_termino		*addnode(t_termino *node, char **data)
{
	t_termino	*p_node;
	t_termino	*tmp;

	p_node = (t_termino*)malloc(sizeof(t_termino));
	if (p_node == NULL)
		return (NULL);
	tmp = node->next;
	node->next = p_node;
	p_node->termino = data;
	p_node->next = tmp;
	return (p_node);
}
