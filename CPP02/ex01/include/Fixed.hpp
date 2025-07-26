/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:02:45 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/07/26 10:03:06 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	_fp_value;
		static const int _fract_bits;

	public:
		Fixed();
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed& copy);

		~Fixed();

		Fixed &operator=(const Fixed &src);

		float toFloat(void)const;
		int toInt(void)const;
		int getRawBits(void)const;
		void setRawBits(int const raw);
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);
