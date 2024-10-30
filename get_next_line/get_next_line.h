/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:09:07 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/10/30 22:47:37 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifdef BUFFER_SIZE
#  define BUFFER BUFFER_SIZE
# else
#  define BUFFER 4096
# endif

/* Prototypage des fonctions utils : */
char					*ft_allocate_line(size_t size);
int						increment(void);
size_t					ft_strlen(char *str);
int						ft_read_line(int fd, char *line);

/* Prototypage de la fonction principale : */
char					*get_next_line(int fd);

#endif
