/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 08:54:27 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/21 09:06:36 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] >= 97 && argv[1][i] <= 122)
			{
				j = argv[1][i] - 96;
				while (j > 0)
				{
					write(1, &argv[1][i], sizeof(char));
					j--;
				}
			}
			else if (argv[1][i] >= 65 && argv[1][i] <= 90)
			{
				j = argv[1][i] - 64;
				while (j > 0)
				{
					write(1, &argv[1][i], sizeof(char));
					j--;
				}
			}
			else
				write(1, &argv[1][i], sizeof(char));
			i++;
		}
		write(1, "\n", sizeof(char));
	}

	return (0);
}