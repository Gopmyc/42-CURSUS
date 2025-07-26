/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:01:22 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/07/26 10:01:40 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	private:
		int	_fp_value;
		static const int _fract_bits;

	public:
		Fixed();
		Fixed(const Fixed& copy);

		~Fixed();

		Fixed &operator=(const Fixed &src);

		int getRawBits(void)const;
		void setRawBits(int const raw);

};
