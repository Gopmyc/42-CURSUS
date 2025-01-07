/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:26:14 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/07 09:03:53 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc >= 2)
		printf("test, %s", argv[1]);
	else
		ft_error("Erreur d'argument\n");
	return (0);
}
