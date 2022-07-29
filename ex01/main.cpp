/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:25:38 by sichoi            #+#    #+#             */
/*   Updated: 2022/07/29 22:32:31 by sichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <iostream>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

typedef struct s_data
{
	std::string	name;
	int			data;
}	Data;

uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	uintptr_t	p;
	Data		*d;

	d = new Data();
	d->data = 42;
	d->name = "sichoi";
	p = serialize(d);
	d = deserialize(p);
	std::cout << "p: " << "0x" << std::hex << p << std::dec << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << GREEN << d->data << " " << d->name << RESET << std::endl;
	delete d;
	// system("leaks serialization");
	return (0);
}
