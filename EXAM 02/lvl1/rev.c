/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:08:15 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/21 09:15:46 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	if (argc == 2)
	{
		i = 0;

		while (argv[1][i] != '\0')
			i++;
		while (i > 0)
			write(1, &argv[1][--i], sizeof(char));
	}
	write(1, "\n", sizeof(char));

	return (0);
}