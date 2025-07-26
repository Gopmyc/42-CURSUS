/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:07:35 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/07/26 10:08:03 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& copy);

		~Point();

		Point &operator=(const Point &src);

		const Fixed &getX(void)const;
		const Fixed &getY(void)const;
};

std::ostream	&operator<<(std::ostream &o, Point const point);
