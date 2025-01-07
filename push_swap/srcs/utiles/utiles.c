/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:39:28 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/07 09:02:21 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_error(char *msg)
{
	write(STDERR_FILENO, "PUSH SWAP : ", 12);
	while (*msg != '\0')
		write(STDERR_FILENO, msg++, 1);
	write(STDERR_FILENO, "\n", 1);
	exit(-1);
}
