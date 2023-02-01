/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 04:27:21 by maboulho          #+#    #+#             */
/*   Updated: 2023/02/01 02:31:40 by maboulho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cube.h"

int	lenght(int fd, char *s)
{
	int		lines;
	char	*tmp;

	lines = -1;
	fd = open (s, O_RDONLY);
	while (1)
	{
		if (lines == -1)
			lines++;
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		free(tmp);
		lines++;
	}
	free(tmp);
	return (lines);
}

int	check_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_first_line(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_strlen(s) > 0 && s[i] != '1' && s[i] != ' ' && s[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

void	init_values(t_cube *p)
{
	p->index = 0;
	p->last_line = 0;
	p->s = 0;
	p->e = 0;
	p->w = 0;
	p->n = 0;
	p->f = 0;
	p->c = 0;
	p->six = 0;
	p->cc = NULL;
	p->we = NULL;
	p->fc = NULL;
	p->no = NULL;
	p->fc = NULL;
	p->ea = NULL;
	p->start = 0;
	p->end = 0;
	p->j = 0;
}

void	check_befor_map(t_cube *p)
{
	int	i;

	i = 0;
	while (p->map[i])
	{
		if (ft_strlen(p->map[i]) > 0 && check_spaces(p->map[i])
			&& check_first_line(p->map[i]))
		{
			i++;
			p->six++;
		}
		else if (ft_strlen(p->map[i]) == 0 || !(check_spaces(p->map[i]))
			|| p->map[i][0] == '\n')
			i++;
		else if (!check_first_line(p->map[i]))
			break ;
	}
	if (p->six == 6)
	{
		p->index = i;
		check_map_values(p);
	}
	else
		error_textures();
}