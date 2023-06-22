/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:18:21 by mobo              #+#    #+#             */
/*   Updated: 2023/06/20 22:18:22 by mobo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"User.hpp"
#include"DataBase.hpp"
int	main()
{

	int chose;
	std::cout << "LOGIN : 1" << std::endl;
	std::cout << "REGISTER : 2" << std::endl;
	std::cout << "[1/2] : ";
	std::cin >> chose;
	DATABASE db;
	if (chose == 1)
	{
		if (db.LOGIN() == false)
			std::cout << "username or password incorrect" << std::endl;
	}
	else if (chose == 2)
	{
		db.REGISTER();
	}
	else
		std::cout << "No Operation availabe for this option" << std::endl;
	//if Register chosen i had to ask for username and Email and passowrd and to confirm password 
		//then i had to ask for email
		//if an error occured during the regestration i had to throw an exception in the main step and my programe should quit imidiatly
	//
	return (0);
}
