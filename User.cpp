/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:18:09 by mobo              #+#    #+#             */
/*   Updated: 2023/06/20 22:18:11 by mobo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"User.hpp"

USER::USER()
{}

USER::USER(const USER &user)
{
	*this = user;
}

USER &USER::operator=(const USER &user)
{
	this->name = user.getName();
	this->laste_name = user.getLastName();
	this->email = user.getEmail();
	this->username = user.getUserName();
	this->password = user.getPassword();
	return (*this);
}

void	USER::setName(const std::string &name)
{
	this->name = name;
}
const std::string &USER::getName() const
{
	return (this->name);
}

void	USER::setLastName(const std::string &lastName)
{
	this->laste_name = lastName;
}
const std::string &USER::getLastName() const
{
	return (this->laste_name);
}

void	USER::setUserName(const std::string &username)
{
	this->username = username;
}
const std::string &USER::getUserName() const
{
	return (this->username);
}

void	USER::setEmail(const std::string &email)
{
	this->email = email;
}
const std::string &USER::getEmail() const
{
	return (this->email);
}

void	USER::setPassword(const std::string &password)
{
	this->password = password;
}
const std::string &USER::getPassword() const
{
	return (this->password);
}

std::string USER::GET_USER_INFO() const
{
	return (this->getName() + "," + this->getLastName() + "," + this->getUserName() + "," + this->getEmail() + "," + this->getPassword() + "\n");
}

USER::~USER(){}