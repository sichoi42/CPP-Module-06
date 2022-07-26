/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:58:11 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/27 01:23:28 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong Arguments!!" << std::endl;
		return (1);
	}
	char *p = NULL;
	// std::strtod(argv[1], &p);
	double value = std::strtod(argv[1], &p);
	std::cout << value << std::endl;
	std::cout << *p << std::endl;
	// Conversion(argv[1]).stoc();
	// Conversion(argv[1]).stoi();
	// Conversion(argv[1]).stof();
	// Conversion(argv[1]).stod();
	return (0);
}
