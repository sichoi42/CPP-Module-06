/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:25:38 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/29 22:58:32 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Base	*generate(void)
{
	double r = static_cast<double>(rand() % 101) / 100;
	if (r <= static_cast<double>(1) / 3)
		return (new A());
	else if (r <= static_cast<double>(2) / 3)
		return (new B());
	return (new C());
}

void	identify(Base *p)
{
	A	*a = dynamic_cast<A *>(p);
	B	*b = dynamic_cast<B *>(p);
	C	*c = dynamic_cast<C *>(p);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A&	a = dynamic_cast<A&>(p);
		std::cout << &a << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		B&	b = dynamic_cast<B&>(p);
		std::cout << &b << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		C&	c = dynamic_cast<C&>(p);
		std::cout << &c << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	test1(void)
{
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "==============" << std::endl;
		Base	*b = generate();
		identify(b);
		delete b;
		std::cout << "==============" << std::endl;
	}
}

void	test2(void)
{
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "==============" << std::endl;
		Base	*tmp = generate();
		Base&	b = *tmp;
		identify(b);
		delete tmp;
		std::cout << "==============" << std::endl;
	}
}

int	main(void)
{
	srand(time(NULL));
	test1();
	// test2();
	// system("leaks identify");
	return (0);
}
