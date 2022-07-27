/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:17:14 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/27 14:12:14 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <sstream>
# include <exception>
# include <cmath> // std::isnan std::isinf
# include <cctype> // std::isprint

class Conversion
{
	private:
		std::string	_input;
		double		_value;
		char		*_type;
		bool		_error;

		Conversion(void);

	public:
		Conversion(const std::string& input);
		~Conversion();
		Conversion(const Conversion& con);

		Conversion&	operator=(const Conversion& con);
		char		stoc(void) const;
		int			stoi(void) const;
		float		stof(void) const;
		double		stod(void) const;
		void		printChar(void) const;
		void		printInt(void) const;
		void		printFloat(void) const;
		void		printDouble(void) const;
		bool		getError(void) const;
};

std::ostream&	operator<<(std::ostream& o, const Conversion& con);

#endif
