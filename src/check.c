/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 13:26:46 by torange           #+#    #+#             */
/*   Updated: 2020/01/22 22:05:17 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_terminos				g_terminos[] =
{
	{"###.#"},
	{"#.###"},
	{"###...#"},
	{"#...###"},
	{"##..#...#"},
	{"##...#...#"},
	{"#...#...##"},
	{"#...#..##"},
	{"####"},
	{"#...#...#...#"},
	{"##..##"},
	{"##.##"},
	{"##...##"},
	{"#...##...#"},
	{"#..##..#"},
	{"###..#"},
	{"#...##..#"},
	{"#..###"},
	{"#..##...#"}
};

int	ft_strfind(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		if (s1[i] == s2[0])
			while (s1[i + j] == s2[j])
			{
				if (s2[j + 1] == '\0')
					return (1);
				j++;
			}
		i++;
	}
	return (-1);
}

int	check_ter_valid(char *tmp)
{
	int	i;

	i = 0;
	while (i < 19)
	{
		if (ft_strfind(tmp, g_terminos[i].term) == 1)
			return (1);
		i++;
	}
	return (-1);
}

int	check_ter_count(char *tmp)
{
	int	i;
	int	k;
	int j;

	i = 0;
	k = 0;
	j = 0;
	while (tmp[i])
	{
		if (tmp[i] != '#' && tmp[i] != '.')
			return (-1);
		if (tmp[i] == '#')
			k++;
		if (tmp[i++] == '.')
			j++;
	}
	if (k == 4 && j == 12)
		if (check_ter_valid(tmp) == 1)
			return (1);
	return (-1);
}

int	ter_to_string(char **tmp)
{
	char	*new_ter;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!(new_ter = (char*)malloc(sizeof(char) * 17)))
		return (0);
	while (tmp[i] != NULL)
	{
		j = 0;
		while (tmp[i][j])
			new_ter[k++] = tmp[i][j++];
		i++;
	}
	new_ter[k] = '\0';
	k = check_ter_count(new_ter);
	free(new_ter);
	if (k == 1)
		return (1);
	return (-1);
}

int	ch(char **tmp)
{
	int	i;
	int	j;
	int	k;
	int check_result;

	i = 0;
	k = 0;
	if (tmp == NULL)
		return (-1);
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			k++;
			j++;
		}
		i++;
	}
	check_result = (k == 16) ? ter_to_string(tmp) : 0;
	free_fields(tmp);
	if (check_result == 1)
		return (1);
	return (-1);
}
