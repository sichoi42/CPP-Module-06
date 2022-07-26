/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:17:14 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/27 01:10:24 by sichoi           ###   ########.fr       */
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

		Conversion(void);

	public:
		Conversion(const std::string& input);
		~Conversion();
		Conversion(const Conversion& con);

		Conversion&	operator=(const Conversion& con);
		void		stoc(void) const;
		void		stoi(void) const;
		void		stof(void) const;
		void		stod(void) const;
};

#endif
