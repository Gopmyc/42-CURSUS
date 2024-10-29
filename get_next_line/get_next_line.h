/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:09:07 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/10/29 20:55:22 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

/* Prototypage des fonctions utils : */
char					*ft_allocate_line(size_t size);
int						ft_read_line(int fd, char *line);

/* Prototypage de la fonction principale : */
char					*get_next_line(int fd);