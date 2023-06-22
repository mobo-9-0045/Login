/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 23:11:22 by mobo              #+#    #+#             */
/*   Updated: 2023/06/20 23:11:24 by mobo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"DataBase.hpp"

std::vector<std::string> split(const std::string& str, char delimiter = ' ')
{
    std::vector<std::string> parts;
    std::stringstream stream(str);
    std::string item;
    while (std::getline(stream, item, delimiter)) {
        if (!item.empty())
            parts.push_back(item);
    }
    if (parts.empty())
        parts.push_back(item);
    return (parts);
}

DATABASE::DATABASE()
{
	std::string line;
	std::ifstream f1("DATABASE.TXT", std::ios::in);
	if (!f1.is_open())
	{
		std::cout << "Couldn't find database" << std::endl;
		f1.close();
	}
	getline(f1, line);
	while (!f1.eof())
	{
		getline(f1, line);
		this->database_container.push_back(line);
	}
}

std::string	ft_username()
{
	std::string username;
	std::cout << "username : ";
	std::cin >> username;
	return (username);
}

std::string ft_password()
{
	std::string password;
	std::cout << "password : ";
	std::cin >> password;
	return (password);
}

bool	DATABASE::LOGIN()
{
	std::string username = ft_username();
	std::string password = ft_password();
	std::vector<std::string>::iterator it = this->database_container.begin();
	while (it != this->database_container.end())
	{
		std::vector<std::string> user_info = split(*it, ',');
		if (user_info[2] == username)
		{
			if (user_info[4] == password)
			{
				std::cout << "you lgoed succesfully" << std::endl;
				return (true);
			}
		}
		++it;
	}
	return (false);
}

void	ft_stringHasdigit(std::string str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (isdigit(str[i]))
		{
			std::cout << "digit occured" << std::endl;
			exit (1);
		}
		i++;
	}
}

void	DATABASE::SET_USER_INFO()
{
	std::string name;
	std::string lastname;
	std::string email;
	std::string username;
	std::string password;
	std::string password2;
	std::cout << "Please enter you information carfully" << std::endl;
	std::cout << "Name : ";
	std::cin >> name;
	ft_stringHasdigit(name);
	std::cout << "Last name : ";
	std::cin >> lastname;
	ft_stringHasdigit(lastname);
	std::cout << "Username: ";
	std::cin >> username;
	std::cout << "Email : ";
	std::cin >> email;
	std::cout << "Password : ";
	std::cin >> password;
	std::cout << "Confirm password : ";
	std::cin >> password2;
	if (password != password2)
	{
		std::cout << "Make sure confirmation password and the password are the same" << std::endl;
		exit (1);
	}
	this->user.setName(name);
	this->user.setLastName(lastname);
	this->user.setUserName(username);
	this->user.setEmail(email);
	this->user.setPassword(password);
}

void	DATABASE::REGISTER()
{
	bool CHECK_IF_AN_USER_FOUND_IN_DATABASE = false;
	this->SET_USER_INFO();
	std::ofstream F("DATABASE.TXT", std::ios::app);
	if (!F.good())
	{
		std::cout << "Error try again later" << std::endl;
		exit (0);
	}
	// i had to check if the user is not exist then i had to add it to database
	std::vector<std::string>::iterator it = this->database_container.begin();
	while (it != this->database_container.end())
	{
		if (*it+"\n" == this->user.GET_USER_INFO())
			CHECK_IF_AN_USER_FOUND_IN_DATABASE = true;
		++it;
	}
	if (CHECK_IF_AN_USER_FOUND_IN_DATABASE == false)
		F << this->user.GET_USER_INFO();
	else
		std::cout << "Plese the information you provide already exist for another user" << std::endl;
	return ;
}

DATABASE::~DATABASE(){}