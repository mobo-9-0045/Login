/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:18:34 by mobo              #+#    #+#             */
/*   Updated: 2023/06/20 22:18:36 by mobo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
# define USER_HPP
#include<iostream>

class USER
{
	private : 
		std::string name;
		std::string laste_name;
		std::string	username;
		std::string email;
		std::string	password;
		USER(const USER &user);
		USER &operator = (const USER &user);
	public:
		USER();
		void	setName(const std::string &name);
		const std::string &getName() const;

		void	setLastName(const std::string &lastname);
		const std::string &getLastName() const;

		void	setUserName(const std::string &username);
		const std::string &getUserName() const;

		void	setEmail(const std::string &email);
		const std::string &getEmail() const;

		void	setPassword(const std::string &password);
		const std::string &getPassword() const;

		void	CheckEmail_or_password(const std::string pas_or_mail, bool p_or_e) const;
		std::string	GET_USER_INFO() const;
		~USER();
};

#endif
