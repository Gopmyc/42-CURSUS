/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:56:55 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/23 08:41:29 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> 
# include <stdint.h>
# include <stdarg.h>

/* STACK STRUCT */
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

int						ft_atoi(const char *str);
void					ft_bzero(void *s, size_t n);
void					*ft_calloc(size_t nmemb, size_t size);
int						ft_isalnum(int ch);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
int						ft_isnumber(char *str);
char					*ft_itoa(int n);
long					ft_atol(const char *str);
t_stack					*ft_lstlast(t_stack *lst);
int						ft_lstsize(t_stack *lst);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memset(void *pointer, int value, size_t len);
void					ft_putchar_fd(char c, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_putstr_fd(char *s, int fd);
char					**ft_split(const char *s, char c);
char					*ft_strchr(const char *s, int c);
char					*ft_strdup(const char *s);
void					ft_striteri(char *s, void (*f)(unsigned int, char*));
char					*ft_strjoin(char *s1, char *s2);
size_t					ft_strlcat(char *d, const char *s, size_t dstsize);
size_t					ft_strlcpy(char *dst, const char *src, size_t size);
size_t					ft_strlen(const char *s);
char					*ft_strmapi(char const *s,
							char (*f)(unsigned int, char));
int						ft_strncmp(const char *s1,
							const char *s2, size_t n);
char					*ft_strnstr(const char *haystack,
							const char *needle, size_t len);
char					*ft_strrchr(const char *s, int c);
size_t					ft_strrec(char const *s1, char const c);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strtrim(const char *s1, const char *set);
char					*ft_substr(char const *s,
							unsigned int start, size_t len);
int						ft_tolower(int c);
int						ft_toupper(int c);

#endif