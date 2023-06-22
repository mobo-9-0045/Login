/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 23:11:42 by mobo              #+#    #+#             */
/*   Updated: 2023/06/20 23:11:43 by mobo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATABASE_HPP
# define DATABASE_HPP
#include"User.hpp"
#include<fstream>
#include<sstream>
#include<vector>
#include<cctype>
class USER;

class DATABASE
{
	private :
		std::vector<std::string> database_container;
		USER user;
	public:
		DATABASE();
		bool	LOGIN();
		void	SET_USER_INFO();
		void	REGISTER();
		~DATABASE();
};

#endif
