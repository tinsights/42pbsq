/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:06:16 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/16 16:06:18 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
// open the map
// read first line lenght
// check that length is >= 4
// read symbols into data

int	checkFirstLine(t_data *data)
{
	if (data->empty == data->filled
		|| data->filled == data->obstacle
		|| data->empty == data->obstacle)
		data->valid = 0;
	return (data->valid);
}

int	readFirstLine(t_data *data, char *file)
{
	int		i;
	int		fd;
	char	buff[1];
	char	*firstline;


	// read length of first line to get rows, empty, filled
	i = 0;
	fd = open(file, O_RDONLY); // assume opens fine
	while(read(fd, buff, 1) && *buff != '\n')
		i++;
	close(fd);
	// check len of line
	if (i < 4)
	{
		data->valid = 0;
		return (0);
	}

	firstline = malloc(sizeof(char) * i + 1);

	fd = open(file, O_RDONLY); // assume opens fine
	read(fd, firstline, i + 1); // moves buffer to next line
	firstline[i] = '\0';

	// TODO validate that firstline has no repeating chars
	// IF INVALID SET DATA.VALID to 0;
	data->empty = firstline[i-3];
	data->obstacle = firstline[i-2];
	data->filled = firstline[i-1];
	if (!checkFirstLine(data))
	{
		free(firstline);
		return (0);
	}
	data->rows = 0;
	i = 0;
	// does "atoi" to the digits seen in the first row
	while (firstline[i] != data->empty)
	{
		if (firstline[i] >= '0' && firstline[i] <= '9')
		{
			data->rows *= 10;
			data->rows += firstline[i] - 48;
		}
		i++;
	}
	// havent checked that cols are all same length
	data->cols = 0;
	while(read(fd, buff, 1) && *buff != '\n')
		data->cols++;
	close(fd);
	return (1);
}