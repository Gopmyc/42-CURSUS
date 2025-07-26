/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:03:11 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/07/26 10:03:51 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed(): _fp_value(0)
{
	std::cout << "Fixed Default Constructor called" << std::endl;
}

Fixed::Fixed(const int input)
{
	std::cout << "Fixed Int Constructor called" << std::endl;
	this->_fp_value = input << this->_fract_bits;
}

Fixed::Fixed(const float input)
{
	std::cout << "Fixed Float Constructor called" << std::endl;
	this->_fp_value = roundf(input * (1 << this->_fract_bits));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Fixed Copy Constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "Fixed Deconstructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Fixed Assignation operator called" << std::endl;
	if (this != &src)
		this->_fp_value = src.getRawBits();

	return *this;
}

float	Fixed::toFloat(void)const
{
	return ((float)this->_fp_value / (float)(1 << this->_fract_bits));
}

int	Fixed::toInt(void)const
{
	return (this->_fp_value >> this->_fract_bits);
}

int	Fixed::getRawBits(void)const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fp_value);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fp_value = raw;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
