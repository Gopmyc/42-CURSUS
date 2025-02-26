/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:35:28 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/21 09:48:25 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char** argv)
{
	char i;
	
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				argv[1][i] = argv[1][i] + 1;
				if (argv[1][i] > 'z')
					argv[1][i] = argv[1][i] - 26;				
			}
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				argv[1][i] = argv[1][i] + 1;
				if (argv[1][i] > 'Z')
					argv[1][i] = argv[1][i] - 26;
			}
			write(1, &argv[1][i], sizeof(char));
			i++;
		}
	}
	write(1, "\n", sizeof(char));
	
	return (0);
}