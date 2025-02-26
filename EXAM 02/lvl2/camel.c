/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:26:23 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/21 11:18:21 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			while (argv[1][i] == ' ')
				i++;
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				if (i > 0 && ((argv[1][(i - 1)] >= 'A' && argv[1][(i - 1)] <= 'Z') || (argv[1][(i - 1)] >= 'a' && argv[1][(i - 1)] <= 'z')))
					write(1, "_", sizeof(char));
				argv[1][i] = argv[1][i] + 32;
			}
			write(1, &argv[1][i], sizeof(char));
			i++;	
		}
	}
	return (0);
}