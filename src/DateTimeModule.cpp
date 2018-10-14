// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DateTimeModule.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpozinen <dpozinen@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/14 09:39:59 by dpozinen          #+#    #+#             //
//   Updated: 2018/10/14 09:39:59 by dpozinen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "DateTimeModule.hpp"

DateTimeModule::DateTimeModule() {
}

DateTimeModule::~DateTimeModule() {
}

void	DateTimeModule::makeAll() {
	makeDateTime();
}

void	DateTimeModule::update() {
	makeAll();
}

void	DateTimeModule::makeDateTime()
{
	time_t	curTime;

	time(&curTime);
	_dateTime = ctime(&curTime);
}

std::string	DateTimeModule::getDateTime() const {
	return _dateTime;
}