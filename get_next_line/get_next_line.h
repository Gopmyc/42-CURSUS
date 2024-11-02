/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:09:07 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/11/02 00:04:47 by ghoyaux          ###   ########.fr       */
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

/* Utiliser structures pour les variables pour les autres projets */

/* Prototypage des fonctions utils : */
size_t					ft_strlen(char	*str);
int						increment(size_t reset);
char					*extend_size(char *cpy, size_t size);
char					*procedure_useless(ssize_t bytes, char *line);

/* Prototypage de la fonction principale : */
char					*get_next_line(int fd);

#endif
