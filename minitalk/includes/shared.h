/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:20:12 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/10 03:40:52 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>

typedef struct s_mem_node
{
	void				*address;
	struct s_mem_node	*next;
}	t_mem_node;

typedef struct s_mem_manager
{
	t_mem_node			*head;
}	t_mem_manager;

/* --- UTILS FUNCTION --- */

int					ft_error(char *sMsg);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
long				ft_atol(const char *str);
size_t				ft_strlen(const char *s);

/* --- GARBAGE COLLECTOR FUNCTION --- */

t_mem_manager		*gc_init_mem_manager(void);
void				*gc_mem_alloc(t_mem_manager *manager, size_t size);
void				gc_free_all(t_mem_manager *manager);
int					gc_destroy_mem_manager(t_mem_manager *manager);

#endif