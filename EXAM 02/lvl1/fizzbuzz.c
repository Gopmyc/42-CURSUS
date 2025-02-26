/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 08:27:08 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/21 08:36:39 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void ft_putnbr(int n)
{
	char c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	int	i;

	i = 1;

	while (i <= 100)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
		{
			if (i % 3 == 0)
				write(1, "fizz", sizeof(char) * 4);
			if (i % 5 == 0)
				write(1, "buzz", sizeof(char) * 4);
		}
		else
			ft_putnbr(i);
		write(1, "\n", sizeof(char));
		i++;
	}

	return (0);
}