/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:20:14 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/09 10:56:42 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shared.h"

t_mem_manager	*gc_init_mem_manager(void)
{
	t_mem_manager	*manager;

	manager = (t_mem_manager *)malloc(sizeof(t_mem_manager));
	if (!(manager))
		ft_error("Error during memory allocation of manager 'gc'");
	manager->head = NULL;
	return (manager);
}

void	*gc_mem_alloc(t_mem_manager *manager, size_t size)
{
	void		*ptr;
	t_mem_node	*new_node;

	if (!manager || size == 0)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	new_node = (t_mem_node *)malloc(sizeof(t_mem_node));
	if (!new_node)
	{
		free(ptr);
		return (NULL);
	}
	new_node->address = ptr;
	new_node->next = manager->head;
	manager->head = new_node;
	return (ptr);
}

void	gc_free_all(t_mem_manager *manager)
{
	t_mem_node	*current;
	t_mem_node	*tmp;

	if (!manager)
		return ;
	current = manager->head;
	while (current)
	{
		free(current->address);
		tmp = current;
		current = current->next;
		free(tmp);
	}
	manager->head = NULL;
}

int	gc_destroy_mem_manager(t_mem_manager *manager)
{
	if (!manager)
		return (0);
	gc_free_all(manager);
	free(manager);
	return (0);
}
