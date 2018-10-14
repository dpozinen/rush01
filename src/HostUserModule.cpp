// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HostUserModule.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/14 09:18:09 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/14 09:18:09 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "HostUserModule.hpp"
#include "header.hpp"

// TODO: operator= & copy cons

HostUserModule::HostUserModule() {
}

HostUserModule::~HostUserModule() {
}

void	HostUserModule::makeHostName(void)
{
	char	hostName[255];

	gethostname(hostName, 255);
	_hostName = hostName;
}

void	HostUserModule::makeUserName(void)
{
	char	userName[255];

	getlogin_r(userName, 255);
	_userName = userName;
}

void	HostUserModule::makeAll(void)
{
	makeUserName();
	makeHostName();
}

void	HostUserModule::update(void) {
	return ;
}

std::string	HostUserModule::getHostName(void) const {
	return _hostName;
}

std::string	HostUserModule::getUserName(void) const {
	return _userName;
}