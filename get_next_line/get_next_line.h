/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:09:07 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/11/03 06:07:20 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

/* Utiliser structures pour les variables pour les autres projets */
/* @FONCTION | ARGS : fd, buffer
	--> Lire BUFFER_SIZE elements dans le read
		bytes = read(fd, buffer_read, BUFFER_SIZE);
	--> -- BOUCLE WHILE --
		while (bytes > 0)
	--> Si buffer_read[bytes] == '\n' alors ont return le reste
		du debut de la chaine en prenant en compte buffer
			if (buffer)
				return (ft_strcat_dynamic(buffer,
					ft_strndup(buffer_read, 0, bytes)));
				return (ft_strndup(buffer_read, 0, bytes));
		--> Sinon ont copie 1 elements a la fois dans le buffer
			de la fin jusqu'au debut et ont decremente
				buffer[bytes] = buffer_read[bytes];
				bytes--;
	--> -- FIN BOUCLE WHILE -- 
	--> Si ont est sorti de la boucle ont return la fonction recursivement
		return (@FONCTION | ARGS : fd, buffer;)
*/

/* Prototypage des fonctions utils : */
size_t					ft_strlen(char *s);
char					*ft_strjoin(char *left_str, char *buff);
char					*ft_get_line(char *left_str);
char					*ft_next_line(char *left_str);

/* Prototypage de la fonction principale : */
char					*get_next_line(int fd);

#endif
