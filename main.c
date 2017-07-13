/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:20:35 by tle-meur          #+#    #+#             */
/*   Updated: 2016/02/11 16:04:53 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"

int	main(void)
{
	t_filler	f;
	char		*line;

	line = NULL;
	if (!my_first_init(&f, &line))
		return (free_and_quit(&f, &line));
	if (!my_compute(&f))
		return (free_and_quit(&f, &line));
	free_grid(&f.form);
	while (1)
	{
		if (!read_grid(&f.grid, &line))
			return (free_and_quit(&f, &line));
		if (!init_grid(&f.form, &line, PIECE))
			return (free_and_quit(&f, &line));
		if (!my_compute(&f))
			return (free_and_quit(&f, &line));
		free_grid(&f.form);
	}
	return (free_and_quit(&f, &line));
}
