/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:50:52 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/27 01:20:29 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion(const std::string& input) : _input(input), _value(0.0)
{
	try
	{
		char	*p = NULL;
		_value = std::strtod(_input.c_str(), &p);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Conversion::~Conversion()
{

}

Conversion::Conversion(const Conversion& con) : _input(con._input), _value(con._value)
{

}

Conversion&	Conversion::operator=(const Conversion& con)
{
	if (this != &con)
	{
		_input = con._input;
		_value = con._value;
	}
	return (*this);
}

void	Conversion::stoc(void) const
{
	std::cout << "char: ";
	if (std::isnan(_value) || std::isinf(_value))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}

	char	c = static_cast<char>(_value);
	if (std::isprint(c))
	{
		std::cout << c << std::endl;
	}
	else
	{
		std::cout << "Non displayable" << std::endl;
	}
}

void	Conversion::stoi(void) const
{

}

void	Conversion::stof(void) const
{

}

void	Conversion::stod(void) const
{

}
