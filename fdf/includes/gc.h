/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 08:54:39 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/19 09:07:02 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_mem_node
{
	void				*address;
	struct s_mem_node	*next;
}				t_mem_node;

typedef struct s_mem_manager
{
	t_mem_node	*head;
}				t_mem_manager;

/* Memory function : */
t_mem_manager	*init_mem_manager(void);
void			*mem_alloc(t_mem_manager *manager, size_t size);
void			free_all(t_mem_manager *manager);
int				destroy_mem_manager(t_mem_manager *manager);
void			ft_free_tbl(char **array, size_t j);

#endif
