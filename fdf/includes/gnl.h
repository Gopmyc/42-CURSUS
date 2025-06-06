/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 08:54:39 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/19 09:19:37 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* GNL inspired by : https://github.com/goffauxs/fdf/tree/main/get_next_line */

#ifndef GNL_H
# define GNL_H
# include <stdlib.h>
# include <unistd.h>
# include "gc.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef FD_MAX
#  define FD_MAX 8192
# endif

int	get_next_line(int fd, char **line, t_mem_manager *manager);

#endif
