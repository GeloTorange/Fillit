/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:46:14 by torange           #+#    #+#             */
/*   Updated: 2019/12/26 22:07:22 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*init_map(char *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	b[len] = '\0';
	while (i < len)
		((unsigned char *)b)[i++] = (unsigned char)c;
	return (b);
}
