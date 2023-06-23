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
	this->CheckEmail_or_password(email, 0);
	this->email = email;
}
const std::string &USER::getEmail() const
{
	return (this->email);
}

void	USER::CheckEmail_or_password(const std::string pas_or_mail, bool p_or_e) const
{
	bool pass_requirement = false;
	bool pass_requirement2 = false;
	bool mail_requirement1 = false;
	bool mail_requirement2 = false;
	int i;
	if (p_or_e == 1)
	{
		i = 0;
		while (pas_or_mail[i])
		{
			if (pas_or_mail[i] >= 'A' && pas_or_mail[i] <= 'Z')
				pass_requirement = true;
			if (pas_or_mail[i] >= '0' && pas_or_mail[i] <= '9')
				pass_requirement2 = true;
			i++;
		}
		if (pass_requirement == false || pass_requirement2 == false || pas_or_mail.length() < 8)
		{
			std::cout << "Password must have at least One Uppercase and one digit and at least 8 Charachters" << std::endl;
			exit (1);
		}
	}
	if (p_or_e == 0)
	{
		int	number_of_dots = 0;
		i = 0;
		while (pas_or_mail[i])
		{
			if (pas_or_mail[i] == '@')
				mail_requirement1 = true;
			if (pas_or_mail[i] == '.')
			{
				mail_requirement2 = true;
				number_of_dots++;
			}
			i++;
		}
		if (mail_requirement1 == false || mail_requirement2 == false || number_of_dots > 1 || pas_or_mail.length() <= 9)
		{
			std::cout << "Email invalid" << std::endl;
			exit (1);
		}
	}
}

void	USER::setPassword(const std::string &password)
{
	this->CheckEmail_or_password(password, 1);
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
