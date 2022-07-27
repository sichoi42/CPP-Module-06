/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:50:52 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/27 14:19:24 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion(const std::string& input) : \
	_input(input), _value(0.0), _type(NULL), _error(false)
{
	try
	{
		_value = std::strtod(_input.c_str(), &_type);
		if (_value == 0.0 && _input[0] != '+' && _input[0] != '-' \
				&& !isdigit(_input[0]) && _input.length() > 1)
		{
			throw (std::bad_alloc());
		}
		if (*_type && *_type != 'f' && _input.length() > 1)
			throw (std::bad_alloc());
	}
	catch (std::exception& e)
	{
		_error = true;
		std::cerr << e.what() << std::endl;
	}
}

Conversion::~Conversion()
{

}

Conversion::Conversion(const Conversion& con) : \
	_input(con._input), _value(con._value), _type(con._type), _error(con._error)
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

char		Conversion::stoc(void) const
{
	return (static_cast<char>(_value));
}

int	Conversion::stoi(void) const
{
	return (static_cast<int>(_value));
}

float	Conversion::stof(void) const
{
	return (static_cast<float>(_value));
}

double	Conversion::stod(void) const
{
	return (_value);
}

void	Conversion::printChar(void) const
{
	std::cout << "char: ";
	if (std::isnan(_value) || std::isinf(_value))
	{
		std::cout << "impossible" << std::endl;
	}
	else if (std::isprint(stoc()))
	{
		std::cout << "'" << stoc() << "'" << std::endl;
	}
	else
	{
		if (_value == 0.0 && std::isprint(*_type))
			std::cout << *_type << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
}

void	Conversion::printInt(void) const
{
	std::cout << "int: ";
	if (std::isnan(_value) || std::isinf(_value))
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		if (_value == 0.0 && std::isprint(*_type))
			std::cout << static_cast<int>(*_type) << std::endl;
		else
			std::cout << stoi() << std::endl;
	}
}

void	Conversion::printFloat(void) const
{
	std::cout << "float: ";
	if (std::isnan(_value) || std::isinf(_value))
	{
		std::cout << _value;
	}
	else
	{
		if (_value == 0.0 && std::isprint(*_type))
			std::cout << static_cast<float>(*_type);
		else
			std::cout << stof();
		if (stof() - stoi() == 0)
			std::cout << ".0";
	}
	std::cout << "f" << std::endl;
}

void	Conversion::printDouble(void) const
{
	std::cout << "double: ";
	if (_value == 0.0 && std::isprint(*_type))
		std::cout << static_cast<double>(*_type);
	else
		std::cout << stod();
	if (stod() - stoi() == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

bool	Conversion::getError(void) const
{
	return (_error);
}

std::ostream&	operator<<(std::ostream& o, const Conversion& con)
{
	if (con.getError() == true)
	{
		o << "Conversion Error!!" << std::endl;
	}
	else
	{
		con.printChar();
		con.printInt();
		con.printFloat();
		con.printDouble();
	}
	return (o);
}
