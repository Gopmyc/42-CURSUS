/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:41:25 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/10/30 22:05:07 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Erreur d'ouverture du fichier");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		write(1, line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
