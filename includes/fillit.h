/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:16:01 by torange           #+#    #+#             */
/*   Updated: 2020/01/23 19:01:41 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"

typedef struct			s_termino
{
	char				**termino;
	int					x;
	int					y;
	char				nbr;
	struct s_termino	*next;
}						t_termino;

typedef struct			s_map
{
	char				**array;
}						t_map;

typedef struct			s_terminos
{
	char				*term;
}						t_terminos;

int						ch(char **tmp);
int						backtrack_tetr(t_termino *start,
		t_termino *tetr, int size);
int						count_ter(t_termino *list);
int						ft_sqrt(int nb);
int						count_n(char *filename, int i);

char					*init_map(char *b, int c, size_t len);

void					to_fill_it(t_termino *ptr, int size);
void					ft_list_push_back_alt(t_termino *list, char **data);
void					ft_list_push_back(t_termino **begin_list, char **data);
int						lstdel(t_termino *list);

t_termino				*initlist(char **data);
t_termino				*addnode(t_termino *node, char **data);
t_termino				*terminos_input(char *filename);
t_termino				*lstdel_t(t_termino *list);
t_termino				*lstdelroot(t_termino *list);

void					free_fields(char **str);
extern t_terminos		g_terminos[];
extern char				g_nb;

#endif
