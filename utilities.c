/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:42:22 by tle-meur          #+#    #+#             */
/*   Updated: 2016/02/11 14:29:26 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "filler.h"
#include "libft/libft.h"

void	free_grid(t_grid *grid)
{
	int	i;
	int	sizei;

	if (grid->g)
	{
		i = 0;
		sizei = grid->hig;
		while (++i < sizei)
			ft_memdel((void **)&grid->g[i++]);
		ft_memdel((void **)&grid->g);
	}
	grid->hig = 0;
	grid->wid = 0;
}

int		free_and_quit(t_filler *f, char **line)
{
	f->mychars[0] = 0;
	f->mychars[1] = 0;
	f->itschars[0] = 0;
	f->itschars[1] = 0;
	free_grid(&f->form);
	free_grid(&f->grid);
	ft_memdel((void **)line);
	write(1, "0 0\n", 24);
	return (0);
}

void	fill_line(t_grid *grid, int id, char *s)
{
	while (ft_isdigit(*s))
		s++;
	ft_memcpy(grid->g[id], ++s, grid->wid * sizeof(char));
}

int		read_grid(t_grid *grid, char **line)
{
	int	i;
	int	j;

	j = -1;
	while (++j < 50000000)
		;
	if (!read_line(line))
		return (0);
	if (!read_line(line))
		return (0);
	i = -1;
	while (++i < grid->hig)
	{
		if (!read_line(line))
			return (0);
		fill_line(grid, i, *line);
	}
	return (1);
}

int		read_line(char **line)
{
	int	ret;

	while ((ret = ft_gnl(0, line)) != 2)
		if (ret == -1)
			return (0);
	return (1);
}
