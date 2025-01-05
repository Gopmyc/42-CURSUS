/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 08:54:39 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/05 08:57:11 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* GNL inspired by : https://github.com/goffauxs/fdf/tree/main/get_next_line */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef FD_MAX
#  define FD_MAX 8192
# endif

int	get_next_line(int fd, char **line);

#endif
