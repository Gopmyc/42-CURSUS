/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 08:07:51 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/21 08:25:17 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] == '\t' || argv[1][i] == ' ')
			i++;
		while (argv[1][i] != '\t' && argv[1][i] != ' ' && argv[1][i] != '\0')
		{
			write(1, &argv[1][i], sizeof(char));
			i++;
		}
	}
	write(1, "\n", sizeof(char));

	return (0);
}