/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:56:55 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/11/16 01:40:41 by ghoyaux          ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int						ft_atoi(const char *str);
void					ft_bzero(void *s, size_t n);
void					*ft_calloc(size_t nmemb, size_t size);
int						ft_isalnum(int ch);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
char					*ft_itoa(int n);
void					ft_lstadd_back(t_list **lst, t_list *new);
void					ft_lstadd_front(t_list **lst, t_list *new);
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstiter(t_list *lst, void (*f)(void *));
t_list					*ft_lstlast(t_list *lst);
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));
t_list					*ft_lstnew(void *content);
int						ft_lstsize(t_list *lst);
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

/* Function declaration of ft_printf_utils.c : */
ssize_t					ft_putnbrlong_fd(ssize_t n, int fd);
ssize_t					ft_putaddress_fd(void *ptr, int fd);
ssize_t					ft_putnbr_hex_fd(unsigned long n, int fd,
							int uppercase);
char					*ft_strstr(const char *haystack, const char *needle);

/* Function declaration of ft_printf_handle.c : */
int						handle_char(va_list args);
int						handle_string(va_list args);
int						handle_pointer(va_list args);
int						handle_int(va_list args, int is_unisgned);
int						handle_hex(va_list args, char specifier);

/* Function declaration of dt_printf_utils.c : */
int						ft_printf(const char *str, ...);

/* Prototypage des fonctions utils de GNL : */
char					*ft_get_line(char *left_str);
char					*ft_next_line(char *left_str);

/* Prototypage de la fonction principale de GNL : */
char					*get_next_line(int fd);

#endif