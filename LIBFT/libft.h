/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:56:55 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/10/16 04:01:37 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	A FAIRE : Une fois le projet quasi completer -->
		- Verifier que toutes les fonctions commence par 'ft_'
		- Verifer que toutes les fonctions sont delarer dans le .h
		- Tester toutes les fonctions avec un main
			les une apres les autres (meme si c'est long)
		- Migrerer toutes les fichiers .c et le .h dans
			la racine du projet et refaire le Makefile pour qu'il fonctionne
		- Prendre une pause
		- Suprimer ce commentaire
		
	--> Le projet est pret a etre rendu !!
*/
#pragma once

#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <stdint.h>

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_isalnum(int ch);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *pointer, int value, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big,
						const char *little, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_tolower(int c);
int					ft_toupper(int c);