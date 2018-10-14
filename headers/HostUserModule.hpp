// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HostUserModule.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/14 09:14:26 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/14 09:14:26 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HOSTUSERMOD_HPP
# define HOSTUSERMOD_HPP

#include "header.hpp"

class	HostUserModule : public IMonitorModule
{
	private:
		std::string	_hostName;
		std::string	_userName;

	public:
		HostUserModule();
		~HostUserModule();
		void		makeAll(void);
		void		update(void);
		void		makeHostName(void);
		void		makeUserName(void);
		std::string	getHostName(void) const;
		std::string	getUserName(void) const;
};

#endif